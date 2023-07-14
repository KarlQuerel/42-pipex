/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:08:58 by kquerel           #+#    #+#             */
/*   Updated: 2022/12/02 17:39:20 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				i;

	i = ft_nbrlen(n);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[i--] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nbr[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (nbr);
}
