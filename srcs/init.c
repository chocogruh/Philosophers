/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:34:01 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/16 18:47:15 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	args_init(t_data *dt, int nb_args, char **args)
{
	dt->n_philo = ft_atol(args[1]);
	if (dt->n_philo == 0)
	{
		printf("Error : no philo around the table\n");
		return (EXIT_FAILURE);
	}
	dt->ttd = ft_atol(args[2]);
	dt->tte = ft_atol(args[3]);
	dt->tts = ft_atol(args[4]);
	if (nb_args == 6)
		dt->nb_meal = ft_atol(args[5]);
	else
		dt->nb_meal = -1;
	dt->pid = malloc(sizeof(pthread_t) * dt->n_philo);
	dt->philo = malloc(sizeof(t_philo) * dt->n_philo);
	return (EXIT_SUCCESS);
}

void	mutex_init(t_data *dt)
{
	pthread_mutex_init(&dt->lock, NULL);
}

int	init_all(t_data *dt, int nb_args, char **args)
{
	if (args_init(dt, nb_args, args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mutex_init(dt);
	return (EXIT_SUCCESS);
}
