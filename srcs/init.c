/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:34:01 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/14 21:26:33 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	args_init(t_data *dt, int nb_args, char **args)
{
	dt->nb_philo = ft_atol(args[1]);
	dt->ttd = ft_atol(args[2]);
	dt->tte = ft_atol(args[3]);
	dt->tts = ft_atol(args[4]);
	if (nb_args == 6)
		dt->nbe = ft_atol(args[5]);
}
