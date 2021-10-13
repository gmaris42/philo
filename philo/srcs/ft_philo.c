/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/13 15:49:03 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_actu_time(t_philo *roger)
{
	gettimeofday(&roger->tmp_time, NULL);
	roger->time = (roger->tmp_time.tv_sec * 1000000 + roger->tmp_time.tv_usec)
		/ 1000;
}

static void	ft_routine(t_param *param, t_philo *philo, int i)
{
	while (param->info->alive == 1
		&& param->info->nb_finish_eat != param->info->nb_philo)
	{
		ft_eat(philo, i, param);
		if (param->info->nb_finish_eat == param->info->nb_philo)
			break ;
		ft_sleep(philo, i, param);
		if (param->info->nb_finish_eat == param->info->nb_philo)
			break ;
		ft_think(philo, i, param);
	}
}

void	*ft_philo(void *param)
{
	t_param			*parm;
	int				i;
	t_philo			*philo;

	parm = (t_param *)param;
	philo = parm->philo;
	pthread_mutex_lock(&parm->inc);
	i = parm->val_philo;
	++parm->val_philo;
	pthread_mutex_unlock(&parm->inc);
	usleep(10000);
	pthread_mutex_lock(&parm->go);
	pthread_mutex_unlock(&parm->go);
	ft_actu_time(&philo[i]);
	philo[i].spawn = philo[i].time;
	philo[i].last_time_eat = philo[i].time;
	if (i == parm->info->nb_philo - 1)
		pthread_mutex_unlock(&parm->death);
	if (i % 2 == 1 && parm->info->nb_philo != 1)
	{
		while (philo[i - 1].nb_eat == 0)
			usleep(500);
	}
	ft_routine(parm, philo, i);
	return (NULL);
}
