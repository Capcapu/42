/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:39:34 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:51:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_stop(t_philo *philo)
{
	if (!philo)
		return (1);
	pthread_mutex_lock(&philo->time);
	if (get_time() - philo->start_last_meal >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		if (!philo->data->dead_flag)
		{
			philo->data->dead_flag = 1;
			pthread_mutex_unlock(&philo->data->dead_lock);
			pthread_mutex_unlock(&philo->time);
			print_dead(philo);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
	}
	pthread_mutex_unlock(&philo->time);
	return (0);
}

int	check_a_philo_died(t_data *data)
{
	int	ret;

	if (!data || !data->philos)
		return (0);
	pthread_mutex_lock(&data->dead_lock);
	ret = data->dead_flag;
	pthread_mutex_unlock(&data->dead_lock);
	return (ret);
}

int	check_dead_between_forks(t_philo *philo, pthread_mutex_t *fork1)
{
	if (check_a_philo_died(philo->data))
	{
		pthread_mutex_unlock(fork1);
		return (1);
	}
	return (0);
}
