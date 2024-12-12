/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:13:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 17:15:07 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*supervisor(void *p)
{
	t_philo *philo;
	int		i;
	int		min_meal_cnt;

	philo = (t_philo *)p;
	while (!end_status(philo, NULL))
	{
		min_meal_cnt = INT_MAX;
		i = -1;
		while (++i < philo->config.num_philo)
		{
			if (philo->persons[i].last_meal == 0)
				continue ;
			if (philo->config.time_to_die < getms() - philo->persons[i].last_meal)
			{
				state_message(getms(), i + 1, msg_die, &philo->persons[i]);
				pthread_mutex_lock(&philo->end_mutex);
				philo->end = true;
				pthread_mutex_unlock(&philo->end_mutex);
				return (NULL);
			}
			if (philo->persons[i].meal_cnt < min_meal_cnt)
				min_meal_cnt = philo->persons[i].meal_cnt;
		}
		if (min_meal_cnt >= philo->config.min_meal && philo->config.min_meal != -1)
		{
			pthread_mutex_lock(&philo->end_mutex);
			philo->end = true;
			pthread_mutex_unlock(&philo->end_mutex);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
