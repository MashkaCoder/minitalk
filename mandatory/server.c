/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:38 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 03:33:37 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	translate_mes(int sig)
{
	static int	c;
	static int	power;

	if (sig == SIGUSR1)
		c += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar_fd(c, 1);
		power = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_struct;

	sig_struct.sa_handler = &translate_mes;
	if (argc == 1)
	{
		ft_printf("The server PID is: %d\n", getpid());
		while (5)
		{
			sigaction(SIGUSR1, &sig_struct, NULL);
			sigaction(SIGUSR2, &sig_struct, NULL);
			pause();
		}
	}
	return (0);
}
