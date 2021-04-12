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

#include "philo_three.h"

int		init_philosophers(t_data *data)
{
	int		i;
	char	*num;

	i = 0;
	while (i < data->amount)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].times_eaten = 0;
		data->philosophers[i].time_last_eat = 0;
		data->philosophers[i].time_of_death = 0;
		num = ft_itoa(i);
		data->philosophers[i].sem_name = ft_strjoin("eat_sem", num);
		free(num);
		sem_unlink(data->philosophers[i].sem_name);
		if ((data->philosophers[i].eat_sem =
			sem_open(data->philosophers[i].sem_name, O_CREAT, 0666, 1))
			== SEM_FAILED)
			return (0);
		i++;
	}
	return (1);
}

int		init_sem(t_data *data)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_write");
	sem_unlink("sem_eat");
	if ((data->fork_sem = sem_open("sem_fork", O_CREAT, 0666, data->amount))
			== SEM_FAILED ||
		(data->write_sem = sem_open("sem_write", O_CREAT, 0666, 1))
			== SEM_FAILED ||
		(data->eat_sem = sem_open("sem_eat", O_CREAT, 0666, 0))
			== SEM_FAILED)
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
	if (!(data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
							* data->amount)))
		return (NULL);
	if (!(init_philosophers(data)))
		return (NULL);
	if (!(init_sem(data)))
		return (NULL);
	return (data);
}

void	free_data(t_data *data)
{
	int i;

	sem_unlink("sem_fork");
	sem_unlink("sem_write");
	i = -1;
	while (++i < data->amount)
	{
		sem_unlink(data->philosophers[i].sem_name);
		free(data->philosophers[i].sem_name);
		kill(data->philosophers[i].pid, SIGKILL);
	}
	free(data->philosophers);
}
