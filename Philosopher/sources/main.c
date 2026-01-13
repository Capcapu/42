/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:06:06 by csolari           #+#    #+#             */
/*   Updated: 2025/06/20 14:29:11 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (!check_arguments(argc, argv))
		return (1);
	data = init_fill_data(argc, argv);
	if (!data)
		return (1);
	i = 0;
	while (data && i < data->number_of_philo)
	{
		if (data->philos[i])
		{
			if (pthread_join(data->philos[i]->thread, NULL) != 0)
				ft_putstr_fd("Error : failed to join thread\n", 2);
		}
		i++;
	}
	if (pthread_join(data->thread_dead, NULL) != 0)
		ft_putstr_fd("Error : failed to join thread\n", 2);
	free_data(data);
	return (0);
}


//# VALG = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1
// # HELG = valgrind --tool=helgrind --history-level=full --track-lockorders=yes --show-below-main=yes --free-is-write=yes


/*
./philo 5 800 200 200 -> doit boucler
./philo 1 800 200 200 -> doit mourir a 800
./philo 5 600 200 200 -> mourir a 600
./philo 5 800 200 200 3 -> stop quand tout le monde a manger 3x
./philo 200 800 200 200 2 -> stop quand 2 repas
valgrind --tool=helgrind ./philo 5 800 200 200 -> free ok
./philo 5 200 100 100 -> mort 200
./philo 5 2000 1000 1000 -> mort 20000
./philo 3 610 200 200 = pas de mort
./philo 4 200 10000 200 = mort
./philo 199 610 200 200 = pas de mort
./philo 1 2000 200 200 = mort
./philo 10 200 200 200 = mort

./philo 1 800 200 200	=> one death at 800 ms
./philo 3 500 200 400	=> one death at 500 ms
./philo 5 800 200 200	=> infinite
./philo 4 310 200 100	=> one death at 310 ms
./philo 4 410 200 200	=> infinite
./philo 4 200 210 200	=> one death at 200 ms
./philo 4 311 150 150	=> infinite
./philo 4 311 150 162	=> one death at 411 ms or more
*/