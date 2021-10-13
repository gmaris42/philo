/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/12 16:22:29 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_think(t_philo *roger, int i, t_param *param)
{
	ft_actu_time(&roger[i]);
	ft_event(roger[i].time - roger[i].spawn, i, param, THINK_EVENT);
	return (0);
}

int	ft_sleep(t_philo *roger, int i, t_param *param)
{
	ft_event(roger[i].time - roger[i].spawn, i, param, SLEEP_EVENT);
	ft_usleep(roger->info->tt_sleep, roger[i].time);
	return (0);
}
