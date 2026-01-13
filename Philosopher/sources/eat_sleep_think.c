/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:10:02 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:49:02 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exec_eat(t_philo *philo)
{
	if (check_a_philo_died(philo->data))
		return (0);
	pthread_mutex_lock(&philo->time);
	philo->start_last_meal = get_time();
	pthread_mutex_unlock(&philo->time);
	print_eat(philo);
	if (!micro_nap(philo, philo->data->time_to_eat))
		return (0);
	pthread_mutex_lock(&philo->meals_finished);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_finished);
	return (1);
}

int	eat_act_bis(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	if (check_a_philo_died(philo->data))
		return (pthread_mutex_unlock(first_fork), 0);
	print_fork(philo);
	pthread_mutex_lock(second_fork);
	if (check_a_philo_died(philo->data))
	{
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (0);
	}
	print_fork(philo);
	if (!exec_eat(philo))
	{
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (0);
	}
	return (1);
}

int	eat_act(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	if (!philo || !philo->data)
		return (0);
	if (philo->data->number_of_philo == 1)
		return (0);
	if (!eat_act_bis(philo, first_fork, second_fork))
		return (0);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	return (1);
}

int	sleep_act(t_philo *philo)
{
	print_sleep(philo);
	if (!micro_nap(philo, philo->data->time_to_sleep))
		return (0);
	return (1);
}

int	think_act(t_philo *philo)
{
	size_t	time;

	if (philo->data->time_to_sleep
		+ philo->data->time_to_eat > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->time);
		time = philo->data->time_to_die - (philo->start_last_meal - get_time());
		pthread_mutex_unlock(&philo->time);
	}
	else
		time = (philo->data->time_to_die - (philo->data->time_to_eat
					+ philo->data->time_to_sleep)) / 2;
	print_think(philo);
	if (time > 0)
	{
		usleep(time * 1000);
		return (1);
	}
	return (0);
}
