/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:39:33 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/27 17:34:06 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("\nRegular Function::::%li::::\n", strlen(av[1]));
		printf("Amazing Function::::%li::::\n\n", ft_strlen(av[1]));
		return (0);
	}
	return (0);
}
*/
