/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:24 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 03:59:29 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_mess(unsigned char c, int pid)
{
	int	arr[8];
	int	i;

	i = 7;
	while (c > 0)
	{
		if (c % 2 == 1 )
			arr[i] = 1;
		else
			arr[i] = 0;
		c = c / 2;
		i--;
	}
	while (i >= 0)
		arr[i] = 0, i--;
	i = 0;
	while (i < 8)
	{
		if (arr[i] == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	long int	pid;
	int			i;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi_n(argv[1]);
	if (pid == 0)
	{
		ft_printf("Please enter the PID first,then the string.\n");
		exit(EXIT_FAILURE);
	}
	while (argc == 3 && argv[2][i])
	{
		send_mess(argv[2][i], pid);
		i++;
	}
	return (0);
}
