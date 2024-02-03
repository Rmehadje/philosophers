/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:42:43 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 18:26:00 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, "ERROR", 6);
	write(1, str, len);
	write (1, "\n", 1);
}
int		check_if_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int		last_arg_check(char **argv)
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

int		error_messanger(int nbr)
{
	if (nbr == 1)
		ft_putstr(": Wrong Arguments!");
	if (nbr == 2)
		ft_putstr(": Cucked");
	return (1);
}
void		death_print(t_data	*data, int philosopher_id)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%d has died.\n", philosopher_id);
	pthread_mutex_unlock(&data->write_lock);
}
