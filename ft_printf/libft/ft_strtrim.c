/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:42 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:43 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*to_right(char const *s_r, char const *set)
{
	int	i;

	i = 0;
	while (s_r[i] != '\0')
	{
		if (!ft_strchr(set, s_r[i]))
			return ((char *)&s_r[i]);
		i++;
	}
	return ((char *)&s_r[i]);
}

static char	*to_left(char const *s_l, char const *set)
{
	int		len_s;

	len_s = ft_strlen((const char *)s_l);
	while (len_s > 0)
	{
		if (!ft_strchr(set, s_l[len_s - 1]))
			return ((char *)&s_l[len_s - 1]);
		len_s--;
	}
	return ((char *)&s_l[len_s - 1]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_res;
	char	*s_r;
	char	*s_l;
	int		i;

	i = 0;
	s_r = to_right(s1, set);
	if (*s_r == '\0')
	{
		s_res = (char *)malloc(1);
		s_res[i] = '\0';
		return (s_res);
	}
	s_l = to_left(s1, set);
	s_res = (char *)malloc(s_l - s_r + 2);
	if (!s_res)
		return (NULL);
	while (&s_r[i] != s_l + 1)
	{
		s_res[i] = s_r[i];
		i++;
	}
	s_res[i] = '\0';
	return (s_res);
}
