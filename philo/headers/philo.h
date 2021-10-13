/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaris <gmaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:47 by gmaris            #+#    #+#             */
/*   Updated: 2021/09/13 15:47:22 by gmaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <color.h>
# define FORK_EVENT 1
# define FORK_EAT_EVENT 2
# define SLEEP_EVENT 3
# define THINK_EVENT 4
# define DIE_EVENT 5

typedef struct s_info
{
	int			nb_philo;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			nb_iter;
	pthread_t	thread_val[1001];
	int			alive;
	int			philo_end;
	int			nb_finish_eat;
}				t_info;

typedef struct s_philo
{
	struct timeval			tmp_time;
	long long int			spawn;
	long long int			time;
	long long int			last_time_eat;
	int						nb;
	int						nb_eat;
	int						start;
	pthread_t				pthread;
	pthread_mutex_t			fourchette;
	t_info					*info;
}				t_philo;

typedef struct s_param
{
	t_philo			philo[1001];
	pthread_mutex_t	aff;
	pthread_mutex_t	inc;
	pthread_mutex_t	go;
	pthread_mutex_t	death;
	t_info			*info;
	int				i;
	int				val_philo;
	long long int	zero;
	int				start;
}				t_param;

int		ft_get_info(char **argv, t_info *info);
void	*ft_philo(void *param);
void	*ft_monitor(void *param);

void	ft_actu_time(t_philo *roger);
void	ft_check_alive(t_param *parm);

int		ft_eat(t_philo *roger, int i, t_param *param);
int		ft_sleep(t_philo *roger, int i, t_param *param);
int		ft_think(t_philo *roger, int i, t_param *param);

void	ft_usleep(int time_to_wait, long long time);

int		ft_event(long long int time, int i, t_param *parm, int event);
#endif
