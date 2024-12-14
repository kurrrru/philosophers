/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:23 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/14 19:54:56 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_forks(t_person *person);
static void	eat_spaghetti(t_person *person);
static void	wait_person(t_person *person, long duration);
static void	sleep_person(t_person *person);

void	*person_work(void *p)
{
	t_person	*person;

	person = (t_person *)p;
	pthread_mutex_lock(person->meal_mutex);
	person->last_meal = getms();
	pthread_mutex_unlock(person->meal_mutex);
	if (person->id % 2 == 0)
		usleep(5000 - (getms() - person->last_meal));
	while (!end_status(NULL, person))
	{
		take_forks(person);
		eat_spaghetti(person);
		sleep_person(person);
		state_message(person->id, msg_think, person);
	}
	return (NULL);
}

static void	take_forks(t_person *person)
{
	if (person->id % 2 == 0)
	{
		pthread_mutex_lock(person->right_fork);
		state_message(person->id, msg_fork, person);
		pthread_mutex_lock(person->left_fork);
		state_message(person->id, msg_fork, person);
	}
	else
	{
		pthread_mutex_lock(person->left_fork);
		state_message(person->id, msg_fork, person);
		pthread_mutex_lock(person->right_fork);
		state_message(person->id, msg_fork, person);
	}
}

static void	eat_spaghetti(t_person *person)
{
	int	min_meal_cnt;

	state_message(person->id, msg_eat, person);
	pthread_mutex_lock(person->meal_mutex);
	person->meal_cnt++;
	person->last_meal = getms();
	min_meal_cnt = *person->min_meal_cnt;
	pthread_mutex_unlock(person->meal_mutex);
	if (min_meal_cnt == person->config.min_meal)
	{
		pthread_mutex_lock(person->end_mutex);
		*person->end = true;
		pthread_mutex_unlock(person->end_mutex);
	}
	wait_person(person, person->config.time_to_eat);
	pthread_mutex_unlock(person->right_fork);
	pthread_mutex_unlock(person->left_fork);
}

static void	wait_person(t_person *person, long duration)
{
	long	start;
	long	now;

	start = getms();
	while (1)
	{
		now = getms();
		if (now - person->last_meal >= person->config.time_to_die)
		{
			state_message(person->id, msg_die, person);
			pthread_mutex_lock(person->end_mutex);
			*(person->end) = true;
			pthread_mutex_unlock(person->end_mutex);
			break ;
		}
		if (now - start >= duration)
			break ;
		usleep(50);
	}
}

static void	sleep_person(t_person *person)
{
	state_message(person->id, msg_sleep, person);
	wait_person(person, person->config.time_to_sleep);
}
