/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:57:25 by anporced          #+#    #+#             */
/*   Updated: 2023/10/09 21:57:56 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)ptr;
	while (n > 0)
	{
		if (*ptr2 == (unsigned char)c)
			return (ptr2);
		ptr2++;
		n--;
	}
	return (NULL);
}
