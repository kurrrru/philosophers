/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:47:04 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 17:23:25 by nkawaguc         ###   ########.fr       */
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
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			min_meal;
}			t_config;

typedef struct s_person
{
	t_config	config;
	int			id;
	bool		*end;
	int			meal_cnt;
	long		last_meal;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*msg_mutex;
	pthread_mutex_t	*end_mutex;
	pthread_mutex_t	*meal_mutex;
}			t_person;

typedef struct s_philo
{
	t_config		config;
	bool			end;
	t_person		*persons;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_t		supervisor;
}			t_philo;

#endif
