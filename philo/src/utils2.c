/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:54:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 15:57:15 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	end_status(t_philo *philo, t_person *person)
{
	bool	end;

	if (philo)
	{
		pthread_mutex_lock(&philo->end_mutex);
		end = philo->end;
		pthread_mutex_unlock(&philo->end_mutex);
	}
	else
	{
		pthread_mutex_lock(person->end_mutex);
		end = *person->end;
		pthread_mutex_unlock(person->end_mutex);
	}
	return (end);
}