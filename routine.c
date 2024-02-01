/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:26:54 by rmehadje          #+#    #+#             */
/*   Updated: 2024/01/30 16:09:44 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h>

void		philosophing(t_phil	*phil)
{
	print_in_routine("is thinking", phil, phil->id);
}

void		asleep(t_phil	*phil)
{
	print_in_routine("is asleep", phil, phil->id);
	sleep_mode(phil->time_to_sleep);
}

void		munching(t_phil	*phil)
{
	t_data	*data;
	while (!(data->isdead))
	{
		pthread_mutex_lock(phil->right_f);
		print_in_routine("has taken right fork", phil, phil->id);
		pthread_mutex_lock(phil->left_f);
		print_in_routine("has taken left fork", phil, phil->id);
		print_in_routine("is eating", phil, phil->id);
		pthread_mutex_lock(phil->meal_lock);
		phil->eating = 1;
		pthread_mutex_unlock(phil->meal_lock);
		sleep_mode(phil->time_to_eat);
		phil->last_meal = ft_real_time();
		pthread_mutex_lock(phil->meal_lock);
		phil->eating = 0;
		pthread_mutex_unlock(phil->meal_lock);
		pthread_mutex_unlock(phil->left_f);
		pthread_mutex_unlock(phil->right_f);
		pthread_mutex_lock(phil->locked);
		phil->meals_eaten++;
		pthread_mutex_unlock(phil->locked);
		print_in_routine("is sleeping", phil, phil->id);
		philosophing(phil);
	}
}

void	is_it_one(t_phil	*phil)
{
	if (phil->num_of_phils == 1)
	{
		sleep_mode(phil->time_before_death);
		pthread_mutex_unlock(phil->right_f);
		return;
	}
}

void	eat_checker(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		if (data->phils[i].meals_eaten == data->phils[i].times_to_eat)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->isdead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			break;
		}
	}
}

void	death_checker(t_data		*data)
{
	int i;

	usleep(data->phils[i].time_to_eat);
	eat_checker(data);
	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		if (!data->phils[i].eating && ft_real_time() >= (data->phils[i].last_meal + data->phils[i].start))
		{
			pthread_mutex_lock(&data->dead_lock);
			data->isdead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			death_print(data, data->phils[i].id);
			break ;
		}
		i++;
	}
}
