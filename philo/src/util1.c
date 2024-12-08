/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:17:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/09 00:19:35 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

long	ft_atol(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
	{
		if (ret > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MAX);
		if (ret < (LONG_MIN + (*str - '0')) / 10)
			return (LONG_MIN);
		ret = ret * 10 + sign * (*str++ - '0');
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
