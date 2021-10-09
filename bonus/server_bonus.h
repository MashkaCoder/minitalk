/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:44:39 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 18:34:17 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

int		main(int argc, char **argv);
void	translate_mes(int sig, siginfo_t *info, void *tmp);

#endif
