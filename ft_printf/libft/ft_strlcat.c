/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:22 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:23 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	src_size;
	unsigned int	dst_size;

	i = 0;
	k = 0;
	src_size = ft_strlen(src);
	dst_size = ft_strlen((const char *)dst);
	while (dst[i] != '\0')
		i++;
	if (dstsize <= dst_size)
		return (src_size + dstsize);
	if (!src)
		return (dstsize);
	while (src[k] && k + dst_size < dstsize - 1)
	{
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (src_size + dst_size);
}
