/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:57:56 by anporced          #+#    #+#             */
/*   Updated: 2023/10/09 23:21:31 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		k = i;
		while (s[k] == to_find[j] && k < len)
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
