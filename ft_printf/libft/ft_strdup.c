/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:16 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:17 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*s2_start;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1_len + 1));
	s2_start = s2;
	if (!s2)
		return (NULL);
	while (*s1 != '\0')
	{
		*s2 = *s1;
		s1++;
		s2++;
	}
	*s2 = '\0';
	return (s2_start);
}
