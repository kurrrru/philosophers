/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:13:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/14 19:50:29 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	die_to_starvation(t_philo *philo, int i);
static long	get_last_meal(t_philo *philo, int i);
static int	get_meal_cnt(t_philo *philo, int i);

void	*supervisor(void *p)
{
	t_philo	*philo;
	int		i;
	int		min_meal_cnt;

	philo = (t_philo *)p;
	while (!end_status(philo, NULL))
	{
		min_meal_cnt = INT_MAX;
		i = -1;
		while (++i < philo->config.num_philo)
		{
			if (get_last_meal(philo, i) && philo->config.time_to_die
				< getms() - get_last_meal(philo, i))
				return (die_to_starvation(philo, i), NULL);
			if (get_last_meal(philo, i)
				&& get_meal_cnt(philo, i) < min_meal_cnt)
				min_meal_cnt = get_meal_cnt(philo, i);
		}
		pthread_mutex_lock(&philo->meal_mutex);
		philo->min_meal_cnt = min_meal_cnt;
		pthread_mutex_unlock(&philo->meal_mutex);
		usleep(100);
	}
	return (NULL);
}

static void	die_to_starvation(t_philo *philo, int i)
{
	state_message(i + 1, msg_die, &philo->persons[i]);
	pthread_mutex_lock(&philo->end_mutex);
	philo->end = true;
	pthread_mutex_unlock(&philo->end_mutex);
}

static long	get_last_meal(t_philo *philo, int i)
{
	long	last_meal;

	pthread_mutex_lock(philo->persons[i].meal_mutex);
	last_meal = philo->persons[i].last_meal;
	pthread_mutex_unlock(philo->persons[i].meal_mutex);
	return (last_meal);
}

static int	get_meal_cnt(t_philo *philo, int i)
{
	int	meal_cnt;

	pthread_mutex_lock(philo->persons[i].meal_mutex);
	meal_cnt = philo->persons[i].meal_cnt;
	pthread_mutex_unlock(philo->persons[i].meal_mutex);
	return (meal_cnt);
}
