/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:06:14 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:44:04 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	meals_finished;
	int				meals_eaten;
	size_t			start_last_meal;
	pthread_mutex_t	time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				number_of_philo;
	size_t			start_time;
	int				dead_flag;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_times_to_eat;
	pthread_t		thread_dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}					t_data;

// UTILS //

void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int nb);
size_t				get_time(void);
void				init_tab(void **tab, int size);
int					micro_nap(t_philo *philo, size_t time_usleep);

// CHECK_ARGS //

int					check_arguments(int argc, char **argv);

// INITILIZATIONS //

t_data				*init_fill_data(int argc, char **argv);
int					init_philo_tab(t_data *data);

// FREE //

void				free_data(t_data *data);
void				free_philos_tab(t_philo **philos);
void				free_forks_tab(t_data *data);

// ROUTINE //

void				*routine(void *arg);
void				*routine2(void *arg);

// EAT SLEEP THINK //

int					eat_act(t_philo *philo);
int					sleep_act(t_philo *philo);
int					think_act(t_philo *philo);

// CHECK DEAD //

int					check_philo_stop(t_philo *philo);
int					check_a_philo_died(t_data *data);
int					check_dead_between_forks(t_philo *philo,
						pthread_mutex_t *fork1);

// PRINT //

void				print_fork(t_philo *philo);
void				print_eat(t_philo *philo);
void				print_sleep(t_philo *philo);
void				print_think(t_philo *philo);
void				print_dead(t_philo *philo);

#endif