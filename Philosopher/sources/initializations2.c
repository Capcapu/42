/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:10:14 by csolari           #+#    #+#             */
/*   Updated: 2025/06/17 13:36:59 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_zero(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->meals_eaten = 0;
	philo->start_last_meal = 0;
	philo->write_lock = &data->write_lock;
	philo->data = data;
	philo->l_fork = NULL;
	philo->r_fork = NULL;
	pthread_mutex_init(&philo->meals_finished, NULL);
	pthread_mutex_init(&philo->time, NULL);
}

int	init_fill_philo(t_data *data, t_philo **philos_tab, int i)
{
	philos_tab[i] = malloc(sizeof(t_philo));
	if (!philos_tab[i])
		return (free_philos_tab(philos_tab), free_data(data),
			ft_putstr_fd("Malloc error\n", 2), 0);
	init_philo_zero(data, philos_tab[i], i + 1);
	if (data->number_of_philo != 1)
	{
		if (i == 0)
		{
			philos_tab[i]->l_fork = &data->forks[data->number_of_philo - 1];
			philos_tab[i]->r_fork = &data->forks[0];
		}
		else
		{
			philos_tab[i]->l_fork = &data->forks[i - 1];
			philos_tab[i]->r_fork = &data->forks[i];
		}
	}
	if (pthread_create(&philos_tab[i]->thread, NULL, &routine,
			philos_tab[i]) != 0)
		return (ft_putstr_fd("Error : failed to create thread\n", 2), 0);
	return (1);
}

int	init_philo_tab(t_data *data)
{
	t_philo	**philos_tab;
	int		i;

	philos_tab = NULL;
	philos_tab = malloc(sizeof(t_philo *) * (data->number_of_philo + 1));
	if (!philos_tab)
		return (free_data(data), ft_putstr_fd("Malloc error\n", 2), 0);
	init_tab((void **)philos_tab, data->number_of_philo + 1);
	data->philos = philos_tab;
	i = 0;
	while (i < data->number_of_philo)
	{
		if (!init_fill_philo(data, philos_tab, i))
			return (0);
		i++;
	}
	philos_tab[i] = NULL;
	return (1);
}
