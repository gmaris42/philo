/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:29 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/12 16:22:46 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	get_time(long long *actual, struct timeval *tmp_time)
{
	gettimeofday(tmp_time, NULL);
	*actual = (tmp_time->tv_sec * 1000000 + tmp_time->tv_usec) / 1000;
}

void	ft_usleep(int time_to_wait, long long time)
{
	long long		end;
	struct timeval	tmp_time;

	end = time + time_to_wait;
	while (time < end)
	{
		get_time(&time, &tmp_time);
		usleep(50);
	}
}
