/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:47:47 by csolari           #+#    #+#             */
/*   Updated: 2025/06/17 12:24:01 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->forks)
		free_forks_tab(data);
	if (data->philos)
		free_philos_tab(data->philos);
	pthread_mutex_destroy(&(data->dead_lock));
	pthread_mutex_destroy(&data->write_lock);
	free(data);
}

void	free_philo(t_philo *philo)
{
	if (!philo)
		return ;
	pthread_mutex_destroy(&philo->meals_finished);
	pthread_mutex_destroy(&philo->time);
	free(philo);
}

void	free_forks_tab(t_data *data)
{
	int	i;

	i = 0;
	if (!data->forks)
		return ;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

void	free_philos_tab(t_philo **philos)
{
	int	i;

	i = 0;
	if (!philos || !*philos)
		return ;
	while (philos && philos[i])
	{
		free_philo(philos[i]);
		i++;
	}
	free(philos);
}
