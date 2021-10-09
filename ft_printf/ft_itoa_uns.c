/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:57 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:22:58 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	usn_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*convert(char *res, unsigned int n, int len)
{
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	while (n != 0)
	{
		res[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa_uns(unsigned int n)
{
	char	*res;
	int		len;

	len = usn_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = convert(res, n, len);
	return (res);
}
