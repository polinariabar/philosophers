/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:56:56 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/14 14:56:57 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_philosophers(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->amount)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].times_eaten = 0;
		data->philosophers[i].time_last_eat = 0;
		data->philosophers[i].time_of_death = 0;
		if (pthread_mutex_init(&data->philosophers[i].eat_mutex, NULL))
			return (0);
		i++;
	}
	return (1);
}

int		init_mutexes(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->amount)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (0);
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->flag_must_eat = (argc == 6 ? '1' : 0);
	data->times_must_eat = (argc == 6 ? ft_atoi(argv[5]) : 0);
	data->each_philo_eaten = 0;
	if (!(data->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
							* data->amount)))
		return (NULL);
	if (!(data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
							* data->amount)))
		return (NULL);
	if (!(init_philosophers(data)))
		return (NULL);
	if (!(init_mutexes(data)))
		return (NULL);
	return (data);
}

void	free_data(t_data *data)
{
	free(data->fork_mutex);
	free(data->philosophers);
}
