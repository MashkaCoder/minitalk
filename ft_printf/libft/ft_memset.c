/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:24:57 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:24:58 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*a;

	a = b;
	while (len > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
		len--;
	}
	return (a);
}
