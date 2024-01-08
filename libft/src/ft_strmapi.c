/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:07:14 by anporced          #+#    #+#             */
/*   Updated: 2023/10/09 21:11:14 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c))
{
	int		i;
	char	*str;

	i = 0;
	if (s && f)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = 0;
		return (str);
	}
	return (NULL);
}
