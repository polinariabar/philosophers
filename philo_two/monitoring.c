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

#include "philo_two.h"

int		monitoring_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->amount)
	{
		sem_wait(data->philosophers[i].eat_sem);
		if (ft_gettime() > data->philosophers[i].time_of_death + 2)
		{
			sem_wait(data->write_sem);
			ft_putnbr_fd((int)(ft_gettime() - data->time_start), 1);
			write(1, " ", 1);
			ft_putnbr_fd(i, 1);
			ft_putstr_fd(" died", 1);
			write(1, "\n", 1);
			free_data(data);
			return (0);
		}
		sem_post(data->philosophers[i].eat_sem);
	}
	return (1);
}

int		monitoring_times_eaten(t_data *data)
{
	if (data->flag_must_eat && data->each_philo_eaten == data->amount)
	{
		sem_wait(data->write_sem);
		free_data(data);
		return (0);
	}
	return (1);
}
