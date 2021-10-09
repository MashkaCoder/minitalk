/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:36 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:37 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (!needle[0])
		return ((char *)&haystack[0]);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (needle[k] != '\0')
			{
				if (haystack[i + k] != needle[k])
					break ;
				k++;
			}
			if (i + k - 1 < len)
				if (needle[k] == '\0')
					return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
