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

#include "philo_one.h"

int		monitoring_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->amount)
	{
		pthread_mutex_lock(&data->philosophers[i].eat_mutex);
		if (ft_gettime() > data->philosophers[i].time_of_death + 2)
		{
			pthread_mutex_lock(&data->write_mutex);
			ft_putnbr_fd((int)(ft_gettime() - data->time_start), 1);
			write(1, " ", 1);
			ft_putnbr_fd(i, 1);
			ft_putstr_fd(" died", 1);
			write(1, "\n", 1);
			free_data(data);
			return (0);
		}
		pthread_mutex_unlock(&data->philosophers[i].eat_mutex);
	}
	return (1);
}

int		monitoring_times_eaten(t_data *data)
{
	if (data->flag_must_eat && data->each_philo_eaten == data->amount)
	{
		pthread_mutex_lock(&data->write_mutex);
		free_data(data);
		return (0);
	}
	return (1);
}

void	*monitoring(void *var)
{
	t_data	*data;

	data = (t_data *)var;
	while (data->philosophers[data->amount - 1].time_of_death == 0)
	{
		;
	}
	while (1)
		if (monitoring_death(data) == 0 || monitoring_times_eaten(data) == 0)
			return (NULL);
	return (NULL);
}
