/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:23:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 14:53:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	terminate_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->config.num_philo)
		pthread_mutex_destroy(&philo->forks[i]);
	pthread_mutex_destroy(&philo->msg_mutex);
	pthread_mutex_destroy(&philo->end_mutex);
	pthread_mutex_destroy(&philo->meal_mutex);
	free(philo->forks);
	free(philo->persons);
}
