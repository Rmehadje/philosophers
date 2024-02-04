/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:14:37 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 19:12:56 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct			s_phil
{
	int						id;
	int						*dead;
	int						r_fork;
	int						l_fork;
	struct	s_data		*data;
	pthread_t				thread_id;
	int						eating;
	int						p_ate;
	long long				ttd;
	long long						last_meal;
	int						times_to_eat;
	int						meals_eaten;
	int						num_of_phils;
	int						isdead;
	long long					start;
	long long					time_to_eat;
	long long					time_before_death;
	long long					time_to_sleep;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*locked;
	pthread_mutex_t		*right_f;
	pthread_mutex_t		tmp;
	pthread_mutex_t		tmp2;
	pthread_mutex_t		tmp3;
	pthread_mutex_t		tmp4;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*write_lock;
	long long				first_ts;

}							t_phil;

typedef struct			s_data
{
	int						nphilo; // to be fixed
	int						start_time;
	int						dead;
	int						isdead;
	int						ate;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		forks[200];
	pthread_t				thread[200];
	t_phil		phils[200];
}							t_data;


int	final_init(t_data	*data);
int		init_args(char **argv);
int		init_forks(t_data *data);
int		init_philos(t_data	*data);

int		ft_atoi(char	*str);
long long	ft_real_time(void);
long	long		time_diff(long long now, long long earlier);
void		print_in_routine(char *str, t_phil *phil, int id);
int		sleep_mode(size_t		MS);

void		philosophing(t_phil	*phil);
void		asleep(t_phil	*phil);
void		*munching(void	*param);

void		ft_putstr(char *str);
int		error_messanger(int nbr);

void	destroy_all(t_data	*data);
int	death_checker(t_data		*data);
void		death_print(t_data	*data, int philosopher_id);
int		init_threads(t_data	*data);
void		eating(t_phil *phil);
int	eat_checker(t_data *data);
void	death(t_data *data);

#endif