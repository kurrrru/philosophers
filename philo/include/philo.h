/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:46:35 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 18:11:18 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "include.h"
# include "macro.h"
# include "struct.h"

// === process_input ===
// process_input.c
int		process_input(int argc, char **argv, t_philo *philo);

// === config_philo ===
// init_philo.c
int		init_philo(t_philo *philo);
// free_philo.c
void	terminate_philo(t_philo *philo);

// === exec_philo ===
// launch.c
void	launch(t_philo *philo);
// person.c
void	*person(void *p);
// supervisor.c
void	*supervisor(void *p);

// === utils ===
// state_message.c
void	state_message(long time, int philo_id,
			t_msg_type msg_type, t_person *person);
// getms.c
long	getms(void);
// util1.c
int		ft_isdigit(int c);
int		ft_isspace(int c);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
// util2.c
bool	end_status(t_philo *philo, t_person *person);

#endif
