/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:01 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:02 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	check_flags(t_flags *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->accuracy_dot = -1;
	flags->minus_in_pres = 0;
}

int	ft_type(char c, t_flags *flags)
{
	if (c == 'c')
		return (print_char(flags, va_arg(flags->ap, int)));
	if (c == 's')
		return (print_str(flags, va_arg(flags->ap, char *)));
	if (c == 'p')
		return (print_p(flags, va_arg(flags->ap, void *)));
	if (c == 'd' || c == 'i')
		return (print_int(flags, va_arg(flags->ap, int)));
	if (c == 'u')
		return (print_uns_int(flags, va_arg(flags->ap, unsigned int)));
	if (c == 'X' || c == 'x')
		return (print_x(flags, va_arg(flags->ap, unsigned int), c));
	if (c == '%')
		return (print_percent(flags));
	return (0);
}

int	indef_flags(const char *s, t_flags *flags, int *i)
{
	while (!ft_isalpha(s[*i]) && s[*i] && s[*i] != '%')
	{
		if (s[*i] == '.')
			flags->accuracy_dot = 0;
		if ((flags->accuracy_dot >= 0 && ft_isdigit((int)s[*i])))
		{
			flags->accuracy_dot = flags->accuracy_dot * 10 + s[*i] - '0';
			if (flags->minus && !flags->width)
				flags->minus_in_pres = 1;
		}
		if (s[*i] == '-')
		{
			if (flags->minus && flags->accuracy_dot >= 0)
				flags->minus_in_pres = 1;
			else
				flags->minus = 1;
		}
		if (s[*i] == '0' && !flags->width && flags->accuracy_dot < 0)
			flags->zero = 1;
		if (ft_isdigit((int)s[*i]) && flags->accuracy_dot < 0)
			flags->width = flags->width * 10 + s[*i] - '0';
		++*i;
	}
	ft_type(s[*i], flags);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	t_flags	flags;

	i = 0;
	len = 0;
	flags.len = 0;
	va_start(flags.ap, s);
	while (s[i] && s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			check_flags(&flags);
			flags.len += indef_flags(s, &flags, &i);
		}
		else
			flags.len += write(1, &s[i], 1);
		i++;
	}
	va_end(flags.ap);
	return (flags.len);
}
