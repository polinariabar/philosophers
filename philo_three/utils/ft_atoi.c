/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:33:15 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/16 12:33:16 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int			count_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] >= 0 && str[i] <= 32)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		else
			break ;
	}
	return (i);
}

int			ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		minus;
	long	check;

	nbr = 0;
	minus = 0;
	i = count_spaces(str);
	if (str[i] == '-' || str[i] == '+')
		minus = i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		nbr = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		check = nbr;
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
		if (nbr < check)
			return ((str[minus] == '-') ? 0 : -1);
	}
	if (str[minus] == '-')
		nbr = -nbr;
	return ((int)nbr);
}
