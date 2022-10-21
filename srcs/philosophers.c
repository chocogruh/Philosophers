/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:11:41 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/21 17:52:20 by mthiesso         ###   ########.fr       */
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
	olihp->n_meal = 0;
	if (olihp->n % 2 == 0)
		usleep(1000 * dt->tte);
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
	printf("%stime(ms) : %zu |Philo n°[%d] [%s]\n", CYAN, time_diff(dt),
		olihp->n, SLEEP);
	if (diy_usleep(dt, olihp, dt->tts) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("%stime(ms) : %zu |Philo n°[%d] [%s]\n", GREEN, time_diff(dt),
		olihp->n, THINK);
	return (EXIT_SUCCESS);
}

int	philo_eat(t_data *dt, t_philo *olihp)
{
	if (take_fork(dt, olihp) == EXIT_FAILURE)
	{
		pthread_mutex_unlock(&dt->fork[olihp->n]);
		pthread_mutex_unlock(&dt->fork[olihp->neighbour]);
		return (EXIT_FAILURE);
	}
	olihp->last_meal = time_diff(dt);
	olihp->n_meal++;
	printf("%stime(ms) : %zu |Philo n°[%d] [%s]\n", YELLOW, time_diff(dt),
		olihp->n, EAT);
	if (diy_usleep(dt, olihp, dt->tte) == EXIT_FAILURE)
	{
		pthread_mutex_unlock(&dt->fork[olihp->n]);
		pthread_mutex_unlock(&dt->fork[olihp->neighbour]);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&dt->fork[olihp->n]);
	pthread_mutex_unlock(&dt->fork[olihp->neighbour]);
	return (EXIT_SUCCESS);
}

int	take_fork(t_data *dt, t_philo *olihp)
{
	pthread_mutex_lock(&dt->fork[olihp->n]);
	printf("%stime(ms) : %zu |Philo n°[%d] [%s] n°[%d]\n", PURP, time_diff(dt),
		olihp->n, FORK, olihp->n);
	if (dt->zombie == 1)
		return (EXIT_FAILURE);
	if (olihp->n == olihp->neighbour)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&dt->fork[olihp->neighbour]);
	printf("%stime(ms) : %zu |Philo n°[%d] [%s] n°[%d]\n", PURP, time_diff(dt),
		olihp->n, FORK, olihp->neighbour);
	return (EXIT_SUCCESS);
}
