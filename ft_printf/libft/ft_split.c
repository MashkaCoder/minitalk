/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:11 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:12 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	res = NULL;
}

static int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	**crear_arr(char const *s, char c, char **res, int count)
{
	int	i;
	int	len;

	i = 0;
	while (count > 0)
	{
		while (*s && *s == c)
			s++;
		len = ft_len(s, c);
		res[i] = ft_substr(s, 0, len);
		if (!res[i])
		{
			ft_free (res, i);
			break ;
		}
		i++;
		s = s + len;
		s++;
		count--;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = ft_count(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	res = crear_arr(s, c, res, count);
	return (res);
}
