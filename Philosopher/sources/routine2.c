/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:33:12 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:51:13 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos_finished_eating(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (!data->philos[i])
			return (0);
		pthread_mutex_lock(&data->philos[i]->meals_finished);
		if (data->philos[i]->meals_eaten != data->number_times_to_eat)
		{
			pthread_mutex_unlock(&data->philos[i]->meals_finished);
			return (0);
		}
		pthread_mutex_unlock(&data->philos[i]->meals_finished);
		i++;
	}
	return (1);
}

int	routine2_bis(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->number_of_philo)
	{
		if (check_philo_stop(data->philos[j]))
			return (0);
		j++;
	}
	if (check_a_philo_died(data))
		return (0);
	if (data->number_times_to_eat != -1)
	{
		if (check_philos_finished_eating(data) == 1)
			return (0);
	}
	usleep(1000);
	return (1);
}

void	*routine2(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!data)
		return (NULL);
	usleep(1000);
	if (data->number_of_philo == 1)
	{
		print_fork(data->philos[0]);
		usleep(data->time_to_die * 1000);
		print_dead(data->philos[0]);
		return (NULL);
	}
	while (1)
	{
		if (!routine2_bis(data))
			return (NULL);
	}
	return (NULL);
}
