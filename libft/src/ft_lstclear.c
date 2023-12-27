/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:22:33 by anporced          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:17 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		size;
	t_list	*aux;

	size = ft_lstsize(*lst);
	while (size > 0)
	{
		aux = *lst;
		*lst = (*lst)->next;
		(*del)(aux->content);
		free(aux);
		size--;
	}
	*lst = NULL;
}
