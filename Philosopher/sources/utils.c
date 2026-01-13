/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:54:53 by csolari           #+#    #+#             */
/*   Updated: 2025/06/19 14:44:22 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!str || !str[i])
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("gettimeofday() error\n", 2);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	init_tab(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = NULL;
		i++;
	}
}

int	micro_nap(t_philo *philo, size_t time_usleep)
{
	size_t	time_start;

	time_start = get_time();
	while (get_time() - time_start < time_usleep)
	{
		if (check_a_philo_died(philo->data))
			return (0);
		usleep(1000);
	}
	return (1);
}
