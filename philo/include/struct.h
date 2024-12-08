/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:47:04 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/09 00:50:46 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "include.h"

typedef enum e_msg_type
{
	msg_fork,
	msg_eat,
	msg_sleep,
	msg_think,
	msg_die
}	t_msg_type;

typedef struct s_config
{
	int			num_philo;
	suseconds_t	time_to_die;
	suseconds_t	time_to_eat;
	suseconds_t	time_to_sleep;
	int			min_meal;
}			t_config;

typedef struct s_philo
{
	t_config	config;
}			t_philo;

#endif
