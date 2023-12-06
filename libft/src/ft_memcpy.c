/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:43:22 by anporced          #+#    #+#             */
/*   Updated: 2023/10/09 22:46:11 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp = (char *)dest;
	temp2 = (char *)src;
	while (n > 0)
	{
		temp[i] = temp2[i];
		i++;
		n--;
	}
	return (dest);
}
