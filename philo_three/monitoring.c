/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:32:20 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/14 18:32:21 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*monitoring_death(void *arg)
{
	t_data	*data;
	int		i;
	int		j;

	data = (t_data *)arg;
	i = data->id;
	j = -1;
	while (1)
	{
		sem_wait(data->philosophers[i].eat_sem);
		if (ft_gettime() > data->philosophers[i].time_of_death + 1)
		{
			sem_wait(data->write_sem);
			ft_putnbr_fd((int)(ft_gettime() - data->time_start), 1);
			write(1, " ", 1);
			ft_putnbr_fd(i, 1);
			ft_putstr_fd(" died", 1);
			write(1, "\n", 1);
			while (j++ < data->amount)
				sem_post(data->eat_sem);
			exit(0);
		}
		sem_post(data->philosophers[i].eat_sem);
	}
	return (NULL);
}

void	*monitoring_times_eaten(void *var)
{
	int		i;
	t_data	*data;

	data = (t_data *)var;
	i = -1;
	while (++i < data->amount)
		sem_wait(data->eat_sem);
	return (NULL);
}
