/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:50 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:22:51 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*hex_convert(char *res, unsigned long n, int len, char c)
{
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	while (n != 0)
	{
		if (n > 9 && c == 'x')
			res[len - 1] = n % 16 + 'a' - 10;
		if (n > 9 && c == 'X')
			res[len - 1] = n % 16 + 'A' - 10;
		if (n % 16 < 10)
			res[len - 1] = n % 16 + 48;
		n = n / 16;
		len--;
	}
	return (res);
}

char	*ft_itoa_hex(unsigned long n, char c)
{
	char	*res;
	int		len;

	len = hex_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = hex_convert(res, n, len, c);
	return (res);
}
