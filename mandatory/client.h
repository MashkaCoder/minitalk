/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 03:00:38 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 18:33:36 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

long int	ft_atoi_n(const char *str);
int			main(int argc, char **argv);
void		send_mess(unsigned char c, int pid);

#endif
