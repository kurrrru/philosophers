/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:26:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/14 20:14:29 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*single_person(void *p);

void	launch(t_philo *philo)
{
	int	i;

	if (philo->config.num_philo == 1)
	{
		pthread_create(&philo->persons[0].thread, NULL, single_person, philo);
		pthread_join(philo->persons[0].thread, NULL);
		return ;
	}
	pthread_mutex_lock(&philo->meal_mutex);
	i = -1;
	while (++i < philo->config.num_philo)
		pthread_create(&philo->persons[i].thread, NULL, person_work,
			&philo->persons[i]);
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_create(&philo->supervisor, NULL, supervisor, philo);
	i = -1;
	while (++i < philo->config.num_philo)
		pthread_join(philo->persons[i].thread, NULL);
	pthread_join(philo->supervisor, NULL);
}

static void	*single_person(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	state_message(1, msg_fork, &philo->persons[0]);
	usleep(philo->config.time_to_die * 1000);
	state_message(1, msg_die, &philo->persons[0]);
	return (NULL);
}
