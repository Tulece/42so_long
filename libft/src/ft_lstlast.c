/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:20:21 by anporced          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:33 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		size;
	t_list	*aux;

	size = ft_lstsize(lst);
	aux = lst;
	while (size > 1)
	{
		aux = aux->next;
		size--;
	}
	return (aux);
}
