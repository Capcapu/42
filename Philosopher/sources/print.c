/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:35:09 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 13:58:06 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void	print_eat(t_philo *philo)
{
	size_t	time;

	if (!philo || !philo->write_lock || !philo->data)
		return ;
	if (check_a_philo_died(philo->data))
		return ;
	pthread_mutex_lock(philo->write_lock);
	pthread_mutex_lock(&philo->time);
	time = philo->start_last_meal - philo->data->start_time;
	pthread_mutex_unlock(&philo->time);
	printf("%s%zu %d is eating%s\n", YELLOW, time, philo->id, RESET);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_sleep(t_philo *philo)
{
	size_t	time;

	if (!philo || !philo->data)
		return ;
	if (check_a_philo_died(philo->data))
		return ;
	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->data->start_time;
	printf("%s%zu %d is sleeping%s\n", CYAN, time, philo->id, RESET);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_think(t_philo *philo)
{
	size_t	time;

	if (!philo || !philo->data)
		return ;
	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->data->start_time;
	printf("%s%zu %d is thinking%s\n", GREEN, time, philo->id, RESET);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_fork(t_philo *philo)
{
	size_t	time;

	if (!philo || !philo->data)
		return ;
	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->data->start_time;
	printf("%s%zu %d has taken a fork%s\n", MAGENTA, time, philo->id, RESET);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_dead(t_philo *philo)
{
	size_t	time;

	if (!philo || !philo->data)
		return ;
	time = get_time() - philo->data->start_time;
	usleep(1000);
	pthread_mutex_lock(philo->write_lock);
	printf("%s%zu %d died%s\n", RED, time, philo->id, RESET);
	pthread_mutex_unlock(philo->write_lock);
}
