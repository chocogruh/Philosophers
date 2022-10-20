/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:41:21 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/20 18:46:46 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*is_there_life(void	*data_t)
{
	t_data	*dt;
	int		i;

	dt = (t_data *)data_t;
	i = 0;
	while (i < dt->n_philo)
	{
		if (time_diff(dt) - dt->philo[i].last_meal > (unsigned long)dt->ttd)
		{
			printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt),
				i, DEAD);
			dt->zombie = 1;
			return (NULL);
		}
		if (i == dt->n_philo - 1)
			i = 0;
		i++;
	}
	return (NULL);
}

void	ending_life(t_data *dt, pthread_t dip)
{
	int	i;

	i = 0;
	while (i < dt->n_philo)
	{
		pthread_join(dt->pid[i], NULL);
		i++;
	}
	pthread_join(dip, NULL);
}
