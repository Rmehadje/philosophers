/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:42:43 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/04 20:31:12 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	last_arg_check(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || (check_if_num(argv[1]) == 1))
		return (write(2, "invalid amount of philosophers\n", 32), 1);
	if (ft_atoi(argv[2]) <= 0 || (check_if_num(argv[2]) == 1))
		return (write(2, "time to die is invalid\n", 24), 1);
	if (ft_atoi(argv[3]) <= 0 || (check_if_num(argv[3]) == 1))
		return (write(2, "time to eat is invalid\n", 24), 1);
	if (ft_atoi(argv[4]) <= 0 || (check_if_num(argv[4]) == 1))
		return (write(2, "sleeping time is invalid\n", 26), 1);
	if (ft_atoi(argv[5]) <= 0 || (check_if_num(argv[5]) == 1))
		return (write(2, "number of times to eat invalid\n", 32), 1);
	return (0);
}

void	death_print(t_data	*data, int philosopher_id)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%lld %d has died.\n", ft_real_time()
		- data->phils[philosopher_id].start, philosopher_id);
	pthread_mutex_unlock(&data->write_lock);
}

void	destroy_all(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->phils[i].tmp);
		pthread_mutex_destroy(&data->phils[i].tmp2);
		pthread_mutex_destroy(&data->phils[i].tmp3);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	free(data);
}

int	final_init(t_data	*data)
{
	data->isdead = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	return (0);
}
