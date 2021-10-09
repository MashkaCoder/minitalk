/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:24:52 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:24:53 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ori;

	dst_ori = dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		src++;
		dst++;
		n--;
	}
	return (dst_ori);
}
