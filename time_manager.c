/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/12 18:35:08 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start(void)
{
	//struct timeval	current_time;
	t_time			*time;

	time = NULL;
	return (0);
}

int	now_time(void)
{
	struct timeval	current_time;
	long int		current_time_ms;

	gettimeofday(&current_time, NULL);
	current_time_ms = current_time.tv_sec * 1000;
	printf("start time : %ld\n", current_time_ms);
	usleep(100);
	printf("end time : %ld\n", current_time_ms);
	return (0);
}
