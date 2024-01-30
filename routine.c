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

#include "philosophers.h"

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
		if (phil->num_of_phils == 1)
		{
			sleep_mode(phil->time_before_death);
			pthread_mutex_unlock(phil->right_f);
			return;
		}
		pthread_mutex_lock(phil->left_f);
		print_in_routine("has taken left fork", phil, phil->id);
		phil->eating = 1;
		print_in_routine("is eating", phil, phil->id);
		pthread_mutex_lock(phil->meal_lock);
		phil->last_meal = ft_real_time();
		pthread_mutex_unlock(phil->meal_lock);
		sleep_mode(phil->time_to_eat);
		phil->eating = 0;
		pthread_mutex_unlock(phil->left_f);
		pthread_mutex_unlock(phil->right_f);
		
	}
}

void		start_routine(t_phil	*phil)
{
	
}