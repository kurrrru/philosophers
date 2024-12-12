/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:15:04 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/12 15:28:39 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (process_input(argc, argv, &philo) == ERROR)
		return (ERROR);
	if (init_philo(&philo) == ERROR)
		return (ERROR);
	launch(&philo);
	terminate_philo(&philo);
	return (0);
}
