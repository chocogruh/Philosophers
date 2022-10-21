/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:41:21 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/21 18:03:39 by mthiesso         ###   ########.fr       */
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
		if (check_meal(dt) == EXIT_FAILURE)
			return (NULL);
		if (time_diff(dt) - dt->philo[i].last_meal >= (unsigned long)dt->ttd)
		{
			dt->zombie = 1;
			printf("%stime(ms) : %zu |Philo n°[%d] [%s]\n", RED, time_diff(dt),
				i, DEAD);
			return (NULL);
		}
		i++;
		if (i == dt->n_philo)
			i = 0;
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

int	check_meal(t_data *dt)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < dt->n_philo)
	{
		if (dt->philo[i].n_meal == dt->nb_meal)
			check++;
		if (dt->nb_meal >= 0 && check >= dt->n_philo)
		{
			dt->zombie = 1;
			usleep(1000);
			printf("%stime(ms) : %zu | all meals were eaten !🍽\n",
				RED, time_diff(dt));
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
