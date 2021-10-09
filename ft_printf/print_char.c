/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:04 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:36:29 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_char(t_flags *flags, int c)
{
	int	i;

	i = 1;
	if (!flags->minus && flags->width)
	{
		while (!flags->minus && flags->width > i)
		{
			flags->len += write(1, " ", 1);
			i++;
		}
		flags->len += write(1, &c, 1);
	}
	else if (flags->minus && flags->width)
	{
		flags->len += write(1, &c, 1);
		while (flags->width > i)
		{
			flags->len += write(1, " ", 1);
			i++;
		}
	}
	else
		flags->len += write(1, &c, 1);
	return (0);
}
