/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:11:41 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/20 19:07:38 by mthiesso         ###   ########.fr       */
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
	if (olihp->n % 2 == 0)
		usleep(1000);
	while (dt->zombie == 0)
	{
		if (philo_eat(dt, olihp) == EXIT_FAILURE)
			return (NULL);
		if (philo_sleep(dt, olihp) == EXIT_FAILURE)
			return (NULL);
	}
	return (NULL);
}

int	philo_sleep(t_data *dt, t_philo *olihp)
{
	printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt),
		olihp->n, SLEEP);
	if (diy_usleep(dt, olihp, dt->tts) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt),
		olihp->n, THINK);
	return (EXIT_SUCCESS);
}

int	philo_eat(t_data *dt, t_philo *olihp)
{
	take_fork(dt, olihp);
	olihp->last_meal = time_diff(dt);
	printf("time(ms) : %zu |Philo n°[%d] [%s]\n", time_diff(dt), olihp->n, EAT);
	if (diy_usleep(dt, olihp, dt->tte) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pthread_mutex_unlock(&dt->fork[olihp->n]);
	pthread_mutex_unlock(&dt->fork[olihp->neighbour]);
	return (EXIT_SUCCESS);
}

void	take_fork(t_data *dt, t_philo *olihp)
{
	pthread_mutex_lock(&dt->fork[olihp->n]);
	printf("time(ms) : %zu |Philo n°[%d] [%s] n°[%d]\n", time_diff(dt),
		olihp->n, FORK, olihp->n);
	pthread_mutex_lock(&dt->fork[olihp->neighbour]);
	printf("time(ms) : %zu |Philo n°[%d] [%s] n°[%d]\n", time_diff(dt),
		olihp->n, FORK, olihp->neighbour);
}
