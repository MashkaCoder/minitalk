/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 03:01:01 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 18:33:51 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		main(int argc, char **argv);
void	translate_mes(int sig);

#endif
