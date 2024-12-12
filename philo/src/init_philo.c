/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:26:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 17:23:16 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_person(t_philo *philo, int i);

int	init_philo(t_philo *philo)
{
	int	i;

	philo->end = false;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->config.num_philo);
	philo->persons = malloc(sizeof(t_person) * philo->config.num_philo);
	if (philo->forks == NULL || philo->persons == NULL)
		return (free(philo->forks), free(philo->persons), ERROR);
	i = -1;
	while (++i < philo->config.num_philo)
		pthread_mutex_init(&philo->forks[i], NULL);
	pthread_mutex_init(&philo->msg_mutex, NULL);
	pthread_mutex_init(&philo->end_mutex, NULL);
	pthread_mutex_init(&philo->meal_mutex, NULL);
	i = -1;
	while (++i < philo->config.num_philo)
		init_person(philo, i);
	return (SUCCESS);
}

static void	init_person(t_philo *philo, int i)
{
	t_person	*person;

	person = &philo->persons[i];
	person->config = philo->config;
	person->id = i + 1;
	person->end = &philo->end;
	person->meal_cnt = 0;
	person->last_meal = 0;
	person->right_fork = &philo->forks[i];
	person->left_fork = &philo->forks[(i + 1) % philo->config.num_philo];
	person->msg_mutex = &philo->msg_mutex;
	person->end_mutex = &philo->end_mutex;
	person->meal_mutex = &philo->meal_mutex;
}
