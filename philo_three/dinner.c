/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:21:03 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/14 18:21:04 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	eat(t_data *data, int i)
{
	sem_wait(data->fork_sem);
	print(i, "has taken right fork", data);
	sem_wait(data->fork_sem);
	print(i, "has taken left fork", data);
	sem_wait(data->philosophers[i].eat_sem);
	data->philosophers[i].time_last_eat = ft_gettime();
	data->philosophers[i].time_of_death = data->philosophers[i].time_last_eat
										+ data->time_to_die;
	data->philosophers[i].times_eaten++;
	if (data->philosophers[i].times_eaten == data->times_must_eat)
		sem_post(data->eat_sem);
	print(i, "is eating", data);
	sem_post(data->philosophers[i].eat_sem);
	usleep(data->time_to_eat * 1000);
	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
}

void	*dinner(void *var)
{
	int			i;
	t_data		*data;
	pthread_t	death;

	data = (t_data *)var;
	i = data->id;
	pthread_create(&death, NULL, monitoring_death, data);
	pthread_detach(death);
	while (1)
	{
		eat(data, i);
		print(i, "is sleeping", data);
		usleep(data->time_to_sleep * 1000);
		print(i, "is thinking", data);
	}
	return (NULL);
}
