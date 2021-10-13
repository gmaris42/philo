/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/13 15:47:29 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_usage(int i)
{
	if (i == 1)
	{
		write(2, "./philo nb_of_philo time_to_die time_to_eat time_to_sleep",
			58);
		write(2, "[nb_of_time_each_philo_must_eat] \n", 35);
		write(2, "\t(all time are in miliseconds)\n", 31);
	}
	else if (i == 2)
		write(2, "Error\nInput invalid please refer to usage (./philo)\n", 53);
	return (1);
}

void	ft_init_mutex(t_param *param, t_info info)
{
	int	i;

	i = 0;
	while (i < info.nb_philo)
	{
		param->philo[i].start = 0;
		pthread_mutex_init(&param->philo[i].fourchette, NULL);
		++i;
	}
	pthread_mutex_init(&(param->aff), NULL);
	pthread_mutex_init(&(param->inc), NULL);
	pthread_mutex_init(&(param->go), NULL);
	pthread_mutex_init(&(param->death), NULL);
	pthread_mutex_lock(&(param->go));
	pthread_mutex_lock(&(param->death));
}

static void	ft_create_philo_init(t_param *param, t_info *info)
{
	param->i = 0;
	param->start = 0;
	param->info = info;
	info->alive = 1;
	info->nb_finish_eat = 0;
}

int	ft_create_philo(t_info info)
{
	t_param		param;

	ft_create_philo_init(&param, &info);
	ft_init_mutex(&param, info);
	while (param.i < info.nb_philo && info.alive == 1)
	{
		param.philo[param.i].nb = param.i + 1;
		param.philo[param.i].info = &info;
		pthread_create(&param.philo[param.i].pthread, NULL, &ft_philo, &param);
		param.i += 1;
	}
	ft_check_alive(&param);
	while (param.i < info.nb_philo)
	{
		pthread_join(param.philo[param.i].pthread, NULL);
		pthread_mutex_destroy(&param.philo[param.i].fourchette);
		++param.i;
	}
	pthread_mutex_destroy(&param.aff);
	pthread_mutex_destroy(&param.inc);
	pthread_mutex_destroy(&param.go);
	pthread_mutex_destroy(&param.death);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	philo;
	int		check;

	if (argc != 5 && argc != 6)
		return (ft_usage(1));
	check = ft_get_info(argv, &philo);
	if (check == 1 || check == 2)
		return (ft_usage(2));
	else if (check != 0)
		return (1);
	ft_create_philo(philo);
	return (0);
}
