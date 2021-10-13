/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/12 16:03:51 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_unlock_fork(pthread_mutex_t *fork_a, pthread_mutex_t *fork_b)
{
	pthread_mutex_unlock(fork_a);
	pthread_mutex_unlock(fork_b);
}

int	ft_eat(t_philo *roger, int i, t_param *parm)
{
	pthread_mutex_t	*fork_b;

	if (i + 1 < roger->info->nb_philo)
		fork_b = &roger[i + 1].fourchette;
	else
		fork_b = &roger[0].fourchette;
	pthread_mutex_lock(&roger[i].fourchette);
	ft_actu_time(&roger[i]);
	ft_event(roger[i].time - roger[i].spawn, i, parm, FORK_EVENT);
	pthread_mutex_lock(fork_b);
	ft_actu_time(&roger[i]);
	ft_event(roger[i].time - roger[i].spawn, i, parm, FORK_EAT_EVENT);
	ft_usleep(roger->info->tt_eat, roger[i].time);
	ft_unlock_fork(&roger[i].fourchette, fork_b);
	ft_actu_time(&roger[i]);
	roger[i].last_time_eat = roger[i].time;
	roger[i].nb_eat += 1;
	if (roger[i].nb_eat == parm->info->nb_iter)
		parm->info->nb_finish_eat += 1;
	return (0);
}
