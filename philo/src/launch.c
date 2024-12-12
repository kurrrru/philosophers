/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:26:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 16:46:09 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	single_person(t_philo *philo);

void	launch(t_philo *philo)
{
	int	i;

	if (philo->config.num_philo == 1)
		return (single_person(philo));
	i = -1;
	while (++i < philo->config.num_philo)
		pthread_create(&philo->persons[i].thread, NULL, person, &philo->persons[i]);
	pthread_create(&philo->supervisor, NULL, supervisor, philo);
	i = -1;
	while (++i < philo->config.num_philo)
		pthread_join(philo->persons[i].thread, NULL);
	pthread_join(philo->supervisor, NULL);
}

static void	single_person(t_philo *philo)
{
	long	time;

	time = getms();
	state_message(time, 1, msg_fork, &philo->persons[0]);
	usleep(philo->config.time_to_die * 1000);
	state_message(time + philo->config.time_to_die, 1, msg_die, &philo->persons[0]);
}
