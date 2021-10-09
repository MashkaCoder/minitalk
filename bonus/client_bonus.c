/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:18 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 18:24:19 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	send_mess(int pid, unsigned char c)
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

void	my_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Signal received\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_struct;
	long int			pid;
	int					i;

	i = 0;
	sig_struct.sa_handler = &my_handler;
	if (argc != 3)
		return (0);
	pid = ft_atoi_n(argv[1]);
	if (pid == 0)
	{
		ft_printf("Please enter the PID first, then the string.\n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &sig_struct, NULL);
	while (argv[2][i])
		send_mess(pid, argv[2][i]), i++;
	while (1)
		pause();
	return (0);
}
