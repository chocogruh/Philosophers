/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/14 21:15:49 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start(t_data *dt)
{
	dt->time = malloc(sizeof(t_time));
	dt->time->start_time = get_now_time();
	return (0);
}

long int	get_now_time(void)
{
	struct timeval	current_time;
	long int		current_time_ms;

	gettimeofday(&current_time, NULL);
	current_time_ms = current_time.tv_sec * 1000;
	return (current_time_ms);
}

int	time_diff(t_data *dt)
{
	int	now_time;

	now_time = get_now_time() - dt->time->start_time;
	printf("now_time : %d\n", now_time);
	return (now_time);
}
