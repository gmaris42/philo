/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:32:07 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/12 16:06:38 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		++i;
	}
	return ((int)(nb * neg));
}

static int	ft_all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		++i;
	}
	return (0);
}

static int	return_zero_iter(void)
{
	write(2,
		"Error\nnumber_of_times_each_philosopher_must_eat can't be 0\n", 60);
	return (12);
}

static void	ft_get_info_atoi(char **argv, t_info *info)
{
	info->nb_philo = ft_atoi(argv[1]);
	info->tt_die = ft_atoi(argv[2]);
	info->tt_eat = ft_atoi(argv[3]);
	info->tt_sleep = ft_atoi(argv[4]);
}

int	ft_get_info(char **argv, t_info *info)
{
	if (ft_all_num(argv[1]) == 1 || ft_all_num(argv[2]) == 1
		|| ft_all_num(argv[3]) == 1 || ft_all_num(argv[4]) == 1)
		return (1);
	ft_get_info_atoi(argv, info);
	if (argv[5] != NULL)
	{
		if (ft_all_num(argv[5]) == 1)
			return (1);
		info->nb_iter = ft_atoi(argv[5]);
		if (info->nb_iter == 0)
			return (return_zero_iter());
	}
	else
		info->nb_iter = 1;
	if (info->nb_iter < 0 || info->nb_philo < 0 || info->tt_die < 0
		|| info->tt_eat < 0 || info->tt_sleep < 0)
		return (2);
	if (argv[5] == NULL)
		info->nb_iter = -1;
	if (info->nb_philo > 200)
	{
		write(2, "Error\nNb_philo max is 200\n", 27);
		return (3);
	}
	return (0);
}
