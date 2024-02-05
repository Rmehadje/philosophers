/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:10:17 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/04 20:28:17 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophing(t_phil	*phil)
{
	print_in_routine("is thinking", phil, phil->id);
}

void	asleep(t_phil	*phil)
{
	print_in_routine("is sleeping", phil, phil->id);
	sleep_mode(phil->time_to_sleep);
}
