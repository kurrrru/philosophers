/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:23 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 22:27:08 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_forks(t_person *person);
static void	eat_spaghetti(t_person *person);
static void	wait_person(t_person *person, long duration);
static void	sleep_person(t_person *person);

void	*person(void *p)
{
	t_person	*person;

	person = (t_person *)p;
	person->last_meal = getms();
	while (!end_status(NULL, person))
	{
		take_forks(person);
		if (end_status(NULL, person))
		{
			pthread_mutex_unlock(person->right_fork);
			pthread_mutex_unlock(person->left_fork);
			break ;
		}
		eat_spaghetti(person);
		if (end_status(NULL, person))
			break ;
		sleep_person(person);
		if (end_status(NULL, person))
			break ;
		state_message(getms(), person->id, msg_think, person);
	}
	return (NULL);
}

static void	take_forks(t_person *person)
{
	if (person->id % 2 == 0)
	{
		if (person->meal_cnt == 0)
			usleep(200);
		pthread_mutex_lock(person->right_fork);
		state_message(getms(), person->id, msg_fork, person);
		pthread_mutex_lock(person->left_fork);
		state_message(getms(), person->id, msg_fork, person);
	}
	else
	{
		pthread_mutex_lock(person->left_fork);
		state_message(getms(), person->id, msg_fork, person);
		pthread_mutex_lock(person->right_fork);
		state_message(getms(), person->id, msg_fork, person);
	}
}

static void	eat_spaghetti(t_person *person)
{
	state_message(getms(), person->id, msg_eat, person);
	pthread_mutex_lock(person->end_mutex);
	pthread_mutex_lock(person->meal_mutex);
	person->meal_cnt++;
	pthread_mutex_unlock(person->meal_mutex);
	if (*person->min_meal_cnt == person->config.min_meal)
		*person->end = true;
	pthread_mutex_unlock(person->end_mutex);
	person->last_meal = getms();
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
			state_message(getms(), person->id, msg_die, person);
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
	state_message(getms(), person->id, msg_sleep, person);
	wait_person(person, person->config.time_to_sleep);
}
