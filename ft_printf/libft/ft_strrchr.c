/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:39 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:25:40 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	while (i >= 0 && string[i] != (unsigned char)symbol)
		i--;
	if (string[i] != (unsigned char)symbol)
		return (NULL);
	return (&((char *)string)[i]);
}
