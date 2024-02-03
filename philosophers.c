/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:27 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 16:56:50 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write (1, "wrong number of arguments", 25);
		return (1);
	}
	if (ft_atoi(argv[1]) == '1')
	{
		printf("0 1 has taken the right fork\n");
		usleep(ft_atoi(argv[2]));
		printf("%d has died!", ft_atoi(argv[2]));
	}
	else
		if (init_args(argv) == -1)
			error_messanger(2);
	return (0);
}
