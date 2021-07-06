/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:48:08 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/17 09:43:24 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlen(char const *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int				ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

long int		ft_abs(long int nbr)
{
	if (nbr < 0)
	{
		return (-nbr);
	}
	return (nbr);
}

char			*ft_str_tolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
