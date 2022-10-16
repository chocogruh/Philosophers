/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:11:41 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/16 20:15:14 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_birth(void *data_t)
{
	t_data		*dt;
	t_philo		*olihp;
	static int	i = 0;

	dt = (t_data *)data_t;
	pthread_mutex_lock(&dt->lock);
	olihp = &dt->philo[i];
	olihp->n = i;
	i++;
	pthread_mutex_unlock(&dt->lock);
	while (1)
	{
		philo_sleep(dt, olihp);
		return (NULL);
	}
	return (NULL);
}

void	philo_sleep(t_data *dt, t_philo *olihp)
{
	printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt), olihp->n, SLEEP);
	usleep(dt->tts * 1000);
}

void	philo_eat(t_data *dt, t_philo *olihp)
{
	int	i;

	pthread_mutex_lock(&dt->fork[olihp->n]);
	//pthread_mutex_lock(&dt->fork[olihp->n + 1]);
	olihp->last_meal = time_diff(dt);
	printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt), olihp->n, EAT);
	usleep(dt->tte * 1000);
	pthread_mutex_unlock(&dt->fork[olihp->n]);
}
