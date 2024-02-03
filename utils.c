/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:53:14 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 17:00:00 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atoi(char	*str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] == '\r' || str[i] == '\f' || str[i] == ' '
		|| str[i] == '\t' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + str[i] - '0';
			i++;
		}
		else
			return (-1);
	}
	return (res * sign);
}


long long	ft_real_time(void)
{
	struct timeval	t;
	
	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	long		time_diff(long long now, long long earlier)
{
	return (now - earlier);
}

void		print_in_routine(char *str, t_phil	*phil, int id)
{
	long long	time;

	pthread_mutex_lock((phil->write_lock));
	time = ft_real_time() - phil->start;
	if	(!(phil->isdead))
	{
		printf("%lli ", time);
		printf("%i ", id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock((phil->write_lock));
}

int		sleep_mode(size_t		MS)
{
	size_t	start;
	
	start = ft_real_time();
	while ((ft_real_time() - start) < MS)
		usleep(500);
	return (0);
}

