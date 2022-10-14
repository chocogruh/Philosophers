/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:50:34 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/14 21:26:33 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	if (check_errors(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	args_init(&dt, argc, argv);
	ft_start(&dt);
	sleep(1);
	time_diff(&dt);
	return (0);
}
