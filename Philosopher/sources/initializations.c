/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:15:18 by csolari           #+#    #+#             */
/*   Updated: 2025/06/13 15:17:49 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data_zero(t_data *data, int argc, char **argv)
{
	data->number_of_philo = 0;
	data->dead_flag = 0;
	data->start_time = get_time();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_times_to_eat = -1;
	if (argc == 6)
		data->number_times_to_eat = ft_atoi(argv[5]);
	data->forks = NULL;
	data->philos = NULL;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
}

int	init_forks_mutex_tab(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->number_of_philo));
	if (!data->forks)
		return (free_data(data), ft_putstr_fd("Malloc error\n", 2), 0);
	while (i < data->number_of_philo)
	{
		usleep(1);
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (1);
}

t_data	*init_fill_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Malloc error\n", 2), NULL);
	init_data_zero(data, argc, argv);
	data->number_of_philo = ft_atoi(argv[1]);
	if (!init_forks_mutex_tab(data))
		return (NULL);
	if (!init_philo_tab(data))
		return (NULL);
	if (pthread_create(&data->thread_dead, NULL, &routine2, data) != 0)
		return (ft_putstr_fd("Error : failed to create thread\n", 2), NULL);
	return (data);
}
