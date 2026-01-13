/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:16:40 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:43:43 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine_bis(t_philo *philo)
{
	if (check_a_philo_died(philo->data))
		return (0);
	if (!eat_act(philo))
		return (0);
	pthread_mutex_lock(&philo->meals_finished);
	if (philo->data->number_times_to_eat != -1
		&& philo->meals_eaten >= philo->data->number_times_to_eat)
	{
		pthread_mutex_unlock(&philo->meals_finished);
		return (0);
	}
	pthread_mutex_unlock(&philo->meals_finished);
	if (check_a_philo_died(philo->data))
		return (0);
	if (!sleep_act(philo))
		return (0);
	if (check_a_philo_died(philo->data))
		return (0);
	if (!think_act(philo))
		return (0);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo || !philo->data)
		return (NULL);
	pthread_mutex_lock(&philo->time);
	philo->start_last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->time);
	if (philo->id % 2 != 0)
	{
		think_act(philo);
		usleep(1000 * philo->id);
	}
	while (1)
	{
		if (!routine_bis(philo))
			break ;
	}
	return (NULL);
}
