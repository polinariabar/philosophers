/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:56:26 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/01 10:26:10 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	int		des;
	int		nb;
	char	d;

	nb = n;
	des = 1;
	while (nb /= 10)
		des *= 10;
	if (n < 0)
		write(fd, "-", 1);
	while (des)
	{
		digit = n / des;
		if (digit < 0)
			digit = -digit;
		d = digit + 48;
		write(fd, &d, 1);
		n %= des;
		des /= 10;
	}
}
