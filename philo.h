/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:17:47 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/14 21:15:35 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "is dead"

typedef struct s_time
{
	long int	start_time;
}	t_time;

typedef struct s_data
{
	int		nb_philo;
	int		ttd;
	int		tte;
	int		tts;
	int		nbe;
	t_time	*time;
}	t_data;

// error.c
int		check_errors(int nb_arg, char **args);
int		are_you_int(int nb_args, char **args);

//init.c
void	args_init(t_data *dt, int nb_args, char **args);

//time_manager.c
int		ft_start(t_data *dt);
long	get_now_time(void);

//utils.c
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		time_diff(t_data *dt);

#endif