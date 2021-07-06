/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:52:38 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:40:51 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexatoi(unsigned long long nbr, int base)
{
	char				*hexa_char;
	unsigned long long	b_nbr;
	int					len;

	hexa_char = 0;
	len = 0;
	b_nbr = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_len2(nbr, base);
	if (!(hexa_char = malloc(sizeof(char) * (len + 1))))
		return (0);
	hexa_char[len] = '\0';
	len--;
	while (len >= 0)
	{
		if ((nbr % base) < 10)
			hexa_char[len] = (nbr % base) + '0';
		else
			hexa_char[len] = (nbr % base) + '7';
		nbr = nbr / base;
		len--;
	}
	return (hexa_char);
}

int		ft_atoi(const char *str)
{
	size_t	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * sign);
}

char	*ft_itoa(int n, t_option option)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	if (sign == -1 && option.dot >= 0)
		len--;
	if (sign == -1 && option.dot < 0 && option.flag_zero == 1)
		len--;
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1 && option.dot < 0 && option.flag_zero == 0)
		c[0] = '-';
	return (c);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
