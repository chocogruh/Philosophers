/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:32 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/14 21:26:40 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	ft_atol(const char *str)
{
	long int	i;
	long int	res;
	long int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
		res = res * 10 + str[i++] - '0';
	if (((res * sign) > INT_MAX) || ((res * sign) < INT_MIN))
	{
		printf("Error !\n");
		exit (0);
	}
	return (sign * res);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
