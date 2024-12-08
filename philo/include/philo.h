/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:46:35 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/09 00:46:19 by nkawaguc         ###   ########.fr       */
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

// === utils ===
// util1.c
int		ft_isdigit(int c);
int		ft_isspace(int c);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

#endif
