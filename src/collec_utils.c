/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:03:38 by anporced          #+#    #+#             */
/*   Updated: 2024/01/09 20:28:30 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_collectibles	*new_collectible(t_axes pos)
{
	t_collectibles	*new;
	static int		collectible;

	if (!collectible)
		collectible = 0;
	new = (t_collectibles *)malloc(sizeof(t_collectibles));
	if (!new)
		return (NULL);
	new->stone = collectible;
	new->next = NULL;
	new->c_pos = pos;
	if (collectible <= 7)
		collectible++;
	if (collectible > 7)
		collectible = 0;
	return (new);
}

int	collec_lst_size(t_collectibles *lst)
{
	int				size;
	t_collectibles	*aux;

	size = 0;
	aux = lst;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_collectibles	*collec_last(t_collectibles *lst)
{
	int				size;
	t_collectibles	*aux;

	size = collec_lst_size(lst);
	aux = lst;
	while (size > 1)
	{
		aux = aux->next;
		size--;
	}
	return (aux);
}

void	add_collec(t_collectibles **lst, t_collectibles *new_lst)
{
	t_collectibles	*aux;

	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	aux = collec_last(*lst);
	aux->next = new_lst;
}

void	lst_collec(t_data *data, t_axes pos)
{
	t_collectibles	*new;

	if (data->collectibles == NULL)
	{
		data->collectibles = new_collectible(pos);
	}
	else
	{
		new = new_collectible(pos);
		add_collec(&data->collectibles, new);
	}
}
