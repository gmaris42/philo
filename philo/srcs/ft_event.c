/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/12 16:04:13 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_event(long long int time, int i, t_param *parm, int event)
{
	pthread_mutex_lock(&parm->aff);
	if (event == DIE_EVENT)
	{
		printf("%s%lld%s %d%s died%s\n", FT_BLUE, time, FT_GREEN, i + 1,
			FT_RED, FT_RESET);
		return (0);
	}
	else if (event == FORK_EVENT)
		printf("%s%lld%s %d%s has taken a fork%s\n",
			FT_BLUE, time, FT_GREEN, i + 1, FT_BROWN, FT_RESET);
	else if (event == FORK_EAT_EVENT)
		printf("%s%lld%s %d%s has taken a fork\n%s%lld%s %d%s is eating%s\n",
			FT_BLUE, time, FT_GREEN, i + 1, FT_BROWN, FT_BLUE, time, FT_GREEN,
			i + 1, FT_LIGHT_PURPLE, FT_RESET);
	else if (event == SLEEP_EVENT)
		printf("%s%lld%s %d%s is sleeping%s\n", FT_BLUE, time, FT_GREEN, i + 1,
			FT_BROWN, FT_RESET);
	else if (event == THINK_EVENT)
		printf("%s%lld%s %d%s is thinking%s\n", FT_BLUE, time, FT_GREEN, i + 1,
			FT_YELLOW, FT_RESET);
	pthread_mutex_unlock(&parm->aff);
	return (0);
}
