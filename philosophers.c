/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:27 by rmehadje          #+#    #+#             */
/*   Updated: 2024/01/30 18:27:48 by rmehadje         ###   ########.fr       */
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
	else
		if (init_args(argv) == -1)
			error_messanger(2);
	/*routine*/;
	return (0);
}