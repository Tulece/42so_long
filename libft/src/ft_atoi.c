/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:49:43 by anporced          #+#    #+#             */
/*   Updated: 2023/11/30 23:07:52 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (res > 214748364 && (sign == 1 || (*s - '0') > 7))
			return (-1);
		else if (res > 214748364 && sign == -1 && (*s - '0') > 8)
			return (0);
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}
/*int	main(int ac, char **av)
{
	(void) ac;
	if (ac == 1)
		return (0);
	printf("%d\n", atoi(av[1]));
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}*/
