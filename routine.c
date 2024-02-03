/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:26:54 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 19:20:57 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		philosophing(t_phil	*phil)
{
	print_in_routine("is thinking", phil, phil->id);
}

void		asleep(t_phil	*phil)
{
	print_in_routine("is sleeping", phil, phil->id);
	sleep_mode(phil->time_to_sleep);
}

void		eating(t_phil *phil)
{
	pthread_mutex_lock(phil->right_f);
	print_in_routine("has taken right fork", phil, phil->id);
	pthread_mutex_lock(phil->left_f);
	print_in_routine("has taken left fork", phil, phil->id);
	print_in_routine("is eating", phil, phil->id);
	pthread_mutex_lock(&phil->tmp);
	phil->eating = 1;
	pthread_mutex_unlock(&phil->tmp);
	sleep_mode(phil->time_to_eat);
	pthread_mutex_lock(&phil->tmp2);
	phil->last_meal = ft_real_time();
	phil->ttd = phil->last_meal + phil->time_before_death - phil->time_to_sleep;
	pthread_mutex_unlock(&phil->tmp2);
	pthread_mutex_lock(&phil->tmp);
	phil->eating = 0;
	pthread_mutex_unlock(&phil->tmp);
	pthread_mutex_unlock(phil->left_f);
	pthread_mutex_unlock(phil->right_f);
	pthread_mutex_lock(&phil->tmp3);
	phil->meals_eaten++;
	pthread_mutex_unlock(&phil->tmp3);
}

void		*munching(void	*param)
{
	t_data	*data;
	t_phil	*phil;
	int			f;

	f = 0;
	phil = (t_phil *)param;
	data = phil->data;
	if ((phil->id % 2)== 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		f = (data->isdead);
		pthread_mutex_unlock(&data->dead_lock);
		if (f)
			break ;
		eating(phil);
		asleep(phil);
		pthread_mutex_lock(&phil->tmp3);
		f = (phil->meals_eaten == phil->times_to_eat);
		pthread_mutex_unlock(&phil->tmp3);
		if (f)
			break ;
		philosophing(phil);
	}
	return (NULL);
}



int	eat_checker(t_data *data)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		pthread_mutex_lock(&data->phils[i].tmp3);
		if (data->phils[i].meals_eaten == data->phils[i].times_to_eat)
		{
			pthread_mutex_unlock(&data->phils[i].tmp3);
			n++;
			break;
		}
		pthread_mutex_unlock(&data->phils[i].tmp3);
		i++;
	}
	if (n == data->phils[i].num_of_phils)
		data->ate = 1;
	return (0);
}

int	death_checker(t_data		*data)
{
	int i;

	i = 0;
	sleep_mode(data->phils[0].time_before_death);
	while (1)
	{
		eat_checker(data);
		death(data);
		pthread_mutex_lock(&data->dead_lock);
		if (data->isdead == 1)
		{
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_lock(&data->write_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->dead_lock);
		if (data->ate)
			break ;
		sleep_mode(data->phils[0].time_before_death / 2);
	}
	return (0);
}

void	death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phils[0].num_of_phils)
	{
		pthread_mutex_lock(&data->phils[i].tmp);
		pthread_mutex_lock(&data->phils[i].tmp2);
		if (!data->phils[i].eating && ft_real_time() >= data->phils[i].ttd)
			{
				pthread_mutex_unlock(&data->phils[i].tmp);
				pthread_mutex_unlock(&data->phils[i].tmp2);
				pthread_mutex_lock(&data->dead_lock);
				data->isdead = 1;
				pthread_mutex_unlock(&data->dead_lock);
				death_print(data, data->phils[i].id);
				break ;
			}
			pthread_mutex_unlock(&data->phils[i].tmp);
			pthread_mutex_unlock(&data->phils[i].tmp2);
			i++;
	}
}
