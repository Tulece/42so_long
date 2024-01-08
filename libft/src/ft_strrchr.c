/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:58:00 by anporced          #+#    #+#             */
/*   Updated: 2023/10/09 23:16:37 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	ch;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len >= 0)
	{
		if ((unsigned char)s[len] == ch)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
