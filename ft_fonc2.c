/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:23:08 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:54:03 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = -1;
	while (src[++i])
		;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int				ft_type_of_format(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_len2(unsigned long long nbr, int base)
{
	int		len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}
