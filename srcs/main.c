/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:50:34 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/21 17:44:14 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data		dt;
	pthread_t	dip;
	int			i;

	i = 0;
	if (check_errors(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all(&dt, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_start(&dt);
	pthread_create(&dip, NULL, is_there_life, &dt);
	while (i < dt.n_philo)
	{
		pthread_create(&dt.pid[i], NULL, philo_birth, &dt);
		i++;
	}
	ending_life(&dt, dip);
	return (EXIT_SUCCESS);
}
