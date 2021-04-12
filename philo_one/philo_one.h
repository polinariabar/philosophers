/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:09:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/12/08 11:09:42 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_philosopher
{
	int				id;
	int				times_eaten;
	unsigned long	time_last_eat;
	unsigned long	time_of_death;
	pthread_mutex_t	eat_mutex;
	pthread_t		thread;
}					t_philosopher;

typedef struct		s_data
{
	int				amount;
	int				id;
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	unsigned int	time_to_eat;
	int				times_must_eat;
	int				each_philo_eaten;

	char			flag_must_eat;
	unsigned long	time_start;

	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	write_mutex;
	t_philosopher	*philosophers;
}					t_data;

/*
** utils.c
*/
int					ft_isdigit(int c);
int					ft_atoi(char *str);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
void				ft_putnbr_fd(int n, int fd);

/*
** init.c
** initialization of structures
*/
int					init_philosophers(t_data *data);
int					init_mutexes(t_data *data);
t_data				*init_data(int argc, char **argv);
void				free_data(t_data *data);

/*
** help.c
** helpfull functions (like utils)
*/
unsigned long		ft_gettime(void);
void				print(int i, char *str, t_data *data);
int					error_message(char *str);
int					check_input_data(int argc, char **argv);

/*
** dinner.c
** eating, sleeping, thinking
*/
void				*dinner(void *var);
void				eat(t_data *data, int i);

/*
** monitoring.c
** monitoring death of a philosopher and times each philosopher ate
*/
void				*monitoring(void *var);
int					monitoring_times_eaten(t_data *data);
int					monitoring_death(t_data *data);

#endif
