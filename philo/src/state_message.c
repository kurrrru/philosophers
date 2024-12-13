/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:22:41 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 11:50:12 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	state_message(int philo_id, t_msg_type msg_type, t_person *person)
{
	const char	*msg[] = {
	[msg_fork] = "has taken a fork",
	[msg_eat] = "is eating",
	[msg_sleep] = "is sleeping",
	[msg_think] = "is thinking",
	[msg_die] = "died"
	};

	pthread_mutex_lock(person->msg_mutex);
	if (!end_status(NULL, person))
		printf("%ld %d %s\n", getms(), philo_id, msg[msg_type]);
	if (msg_type == msg_die)
	{
		pthread_mutex_lock(person->end_mutex);
		*person->end = true;
		pthread_mutex_unlock(person->end_mutex);
	}
	pthread_mutex_unlock(person->msg_mutex);
}
