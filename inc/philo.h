/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:17:47 by mthiesso          #+#    #+#             */
/*   Updated: 2022/10/16 20:12:26 by mthiesso         ###   ########.fr       */
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

# define BORN "is born"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "is dead"
# define FORK "has taken a fork"

typedef struct s_philo
{
	int	n;
	int	last_meal;
	int	neighbour;
}	t_philo;

typedef struct s_time
{
	long int	start_time;
}	t_time;

typedef struct s_data
{
	int				n_philo;
	int				n_fork;
	int				ttt;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_meal;
	pthread_t		*pid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	t_time			*time;
	t_philo			*philo;
}	t_data;

//error.c
int		check_errors(int nb_arg, char **args);
int		are_you_int(int nb_args, char **args);

//init.c
int		args_init(t_data *dt, int nb_args, char **args);
void	mutex_init(t_data *dt);
int		init_all(t_data *dt, int nb_args, char **args);

//time_manager.c
int		ft_start(t_data *dt);
size_t	get_now_time(void);
size_t	time_diff(t_data *dt);

//utils.c
long	ft_atol(const char *str);
int		ft_isdigit(int c);

//philosophers.c
void	*philo_birth(void *data_t);
void	philo_sleep(t_data *dt, t_philo *olihp);

#endif