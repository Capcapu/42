/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:29 by csolari           #+#    #+#             */
/*   Updated: 2024/11/11 16:55:48 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	char	buf[100];
	int		file_des;
	int		i;

	i = -1;
	if (argc == 1)
		return (write(1, "File name missing.\n", 19));
	if (argc > 2)
		return (write(1, "Too many arguments.\n", 20));
	if (argc == 2)
	{
		file_des = open(argv[1], O_RDONLY);
		while (i != 0)
		{
			i = read(file_des, buf, 100);
			write(1, buf, i);
		}
		if (i == -1)
			return (write(1, "Cannot read file.\n", 18));
		close (file_des);
	}
	return (0);
}
