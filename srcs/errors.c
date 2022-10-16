/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:31:54 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/16 14:56:31 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_errors(int nb_arg, char **args)
{
	(void) args;
	if (nb_arg < 5 || nb_arg > 6)
	{
		printf("Error : wrong number of argument\n");
		return (EXIT_FAILURE);
	}
	if (are_you_int(nb_arg, args) == EXIT_FAILURE)
	{
		printf("Error : argument must be positive digit only\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	are_you_int(int nb_args, char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < nb_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
