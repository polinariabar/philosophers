/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:08:57 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/08 11:09:00 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		philosophers(t_data *data)
{
	int			i;
	pthread_t	thread;

	data->time_start = ft_gettime();
	if (pthread_create(&thread, NULL, monitoring_times_eaten, (void *)data))
		return (0);
	i = -1;
	while (++i < data->amount)
	{
		data->id = i;
		data->philosophers[i].time_last_eat = ft_gettime();
		data->philosophers[i].time_of_death =
			data->philosophers[i].time_last_eat + data->time_to_die;
		if ((data->philosophers[i].pid = fork()) < 0)
			return (0);
		else if (data->philosophers[i].pid == 0)
			dinner(data);
		else
			usleep(50);
	}
	if (pthread_join(thread, NULL))
		return (0);
	free_data(data);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	pid_t	pid;

	if (argc != 5 && argc != 6)
		error_message("Invalid number of arguments!");
	if (!(check_input_data(argc, argv)))
		error_message("Invalid format of input data!");
	if (!(data = init_data(argc, argv)))
		error_message("Allocation error!");
	if ((pid = fork()) < 0)
		error_message("Fork error!");
	else if (pid == 0)
		philosophers(data);
	else
		waitpid(-1, NULL, 0);
	return (0);
}
