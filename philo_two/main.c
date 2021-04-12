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

#include "philo_two.h"

int		philosophers(t_data *data)
{
	int			i;

	data->time_start = ft_gettime();
	i = -1;
	while (++i < data->amount)
	{
		data->id = i;
		data->philosophers[i].time_last_eat = ft_gettime();
		data->philosophers[i].time_of_death =
		data->philosophers[i].time_last_eat + data->time_to_die;
		if (pthread_create(&data->philosophers[i].thread, NULL, dinner, data))
			return (0);
		usleep(50);
	}
	while (data->philosophers[data->amount - 1].time_of_death == 0)
		;
	while (1)
		if (monitoring_death(data) == 0 || monitoring_times_eaten(data) == 0)
			return (1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (error_message("Invalid number of arguments!"));
	if (!(check_input_data(argc, argv)))
		return (error_message("Invalid format of input data!"));
	if (!(data = init_data(argc, argv)))
		return (error_message("Allocation error!"));
	if (!(philosophers(data)))
	{
		free_data(data);
		return (error_message("Error!"));
	}
	return (0);
}
