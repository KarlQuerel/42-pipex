/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:42:45 by kquerel           #+#    #+#             */
/*   Updated: 2022/11/23 21:04:25 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char *s = "INTRUSeHeliabonsoir";
	int	c;

	c = 'e';
	printf("\nRegular Function::::%s::::\n", strchr(s, c));
	printf("Amazing Function::::%s::::\n\n", ft_strchr(s, c));
	return (0);
}
*/
