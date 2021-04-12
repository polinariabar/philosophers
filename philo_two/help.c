/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:01:00 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/14 15:01:01 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

unsigned long	ft_gettime(void)
{
	static struct timeval	time;
	uint64_t				t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000);
	return ((unsigned long)t);
}

void			print(int i, char *str, t_data *data)
{
	sem_wait(data->write_sem);
	ft_putnbr_fd((int)(ft_gettime() - data->time_start), 1);
	write(1, " ", 1);
	ft_putnbr_fd(i, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	sem_post(data->write_sem);
}

int				error_message(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int				check_input_data(int argc, char **argv)
{
	int		i;
	int		j;

	j = 1;
	while (j != argc)
	{
		i = 0;
		while (argv[j][i] && argv[j][i] == '+')
			i++;
		while (argv[j][i] && ft_isdigit(argv[j][i]))
			i++;
		if (argv[j][i])
			return (0);
		j++;
	}
	return (1);
}
