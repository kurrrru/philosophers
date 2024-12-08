/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:22:41 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/08 22:49:39 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	state_message(suseconds_t time, int philo_id, t_msg_type msg_type)
{
	const char	*msg[] = {
	[msg_fork] = "has taken a fork",
	[msg_eat] = "is eating",
	[msg_sleep] = "is sleeping",
	[msg_think] = "is thinking",
	[msg_die] = "died"
	};

	printf("%16ld %d %s\n", time / 1000, philo_id, msg[msg_type]);
}
