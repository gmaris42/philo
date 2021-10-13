/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/13 15:48:30 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	get_time(long long *actual)
{
	struct timeval	tmp_time;

	gettimeofday(&tmp_time, NULL);
	*actual = (tmp_time.tv_sec * 1000000 + tmp_time.tv_usec) / 1000;
}

static void	ft_detach(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->info->nb_philo)
	{
		pthread_detach(param->philo[i].pthread);
		++i;
	}
}

static void	ft_wait_start(t_param *parm)
{
	parm->i = 0;
	pthread_mutex_unlock(&parm->go);
	pthread_mutex_lock(&parm->death);
}

void	ft_check_alive(t_param *parm)
{
	t_philo		*philo;
	long long	actual;
	int			i;

	philo = parm->philo;
	ft_wait_start(parm);
	actual = 0;
	while (parm->info->alive == 1
		&& parm->info->nb_finish_eat != parm->info->nb_philo)
	{
		i = 0;
		get_time(&actual);
		while (i < parm->info->nb_philo)
		{
			if (philo[i].last_time_eat + parm->info->tt_die < actual)
			{
				parm->info->alive = 0;
				ft_event(actual - parm->philo[i].spawn, i, parm, DIE_EVENT);
				ft_detach(parm);
				break ;
			}
			++i;
		}
		usleep(1000);
	}
}
