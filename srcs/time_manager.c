/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/16 19:16:41 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_start(t_data *dt)
{
	dt->time = malloc(sizeof(t_time));
	dt->time->start_time = get_now_time();
	return (0);
}

size_t	get_now_time(void)
{
	struct timeval	current_time;
	size_t			current_time_ms;

	gettimeofday(&current_time, NULL);
	current_time_ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (current_time_ms);
}

size_t	time_diff(t_data *dt)
{
	size_t	now_time;

	now_time = get_now_time() - dt->time->start_time;
	return (now_time);
}
