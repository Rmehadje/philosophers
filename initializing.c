/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:13 by rmehadje          #+#    #+#             */
/*   Updated: 2024/01/30 18:30:48 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		init_philos(t_data *data)
{
	int		i;

	final_init(data);
	init_forks(data);
	i = -1;
	while (++i < data->phils[0].num_of_phils)
	{
		data->phils[i].id = i + 1;
		data->phils[i].meals_eaten = 0;
		data->phils[i].eating = 0;
		data->phils[i].start = ft_real_time();
		data->phils[i].last_meal = ft_real_time();
		data->phils[i].meal_lock = &data->meal_lock;
		data->phils[i].write_lock = &data->write_lock;
		data->phils[i].dead_lock = &data->dead_lock;
		data->phils[i].dead = &data->dead;
		data->phils[i].left_f = &data->forks[i];
		data->phils[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int		init_forks(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int		init_args(char **argv)
{
	int	i;
	t_data	*data;

	data = malloc(sizeof(t_data *));
	if (!data)
		return (-1);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data->phils[i].num_of_phils = ft_atoi(argv[1]);
		data->phils[i].time_before_death = ft_atoi(argv[2]);
		data->phils[i].time_to_eat = ft_atoi(argv[3]);
		data->phils[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data->phils[i].times_to_eat = ft_atoi(argv[5]);
		else
			data->phils[i].times_to_eat = -1;
		i++;
	}
	init_philos(data);
	return (0);
}

int	final_init(t_data	*data)
{
	data->isdead = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	return (0);
}
