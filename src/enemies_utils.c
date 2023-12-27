/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:54:50 by anporced          #+#    #+#             */
/*   Updated: 2023/12/27 20:29:40 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemies	*new_enemies(t_axes pos)
{
	t_enemies	*new;
	static int	enemie;

	if (!enemie)
		enemie = 0;
	new = (t_enemies *)malloc(sizeof(t_enemies));
	if (!new)
		return (NULL);
	new->state = enemie;
	new->direction = 0;
	new->next = NULL;
	new->z_pos = pos;
	if (enemie < 7)
		enemie++;
	if (enemie >= 7)
		enemie = 0;
	return (new);
}

int	enemies_lst_size(t_enemies *lst)
{
	int			size;
	t_enemies	*aux;

	size = 0;
	aux = lst;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_enemies	*enemies_last(t_enemies *lst)
{
	int			size;
	t_enemies	*aux;

	size = enemies_lst_size(lst);
	aux = lst;
	while (size > 1)
	{
		aux = aux->next;
		size--;
	}
	return (aux);
}

void	add_enemies(t_enemies **lst, t_enemies *new_lst)
{
	t_enemies	*aux;

	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	aux = enemies_last(*lst);
	aux->next = new_lst;
}

void	lst_enemies(t_data *data, t_axes pos)
{
	t_enemies	*new;

	if (data->enemies == NULL)
		data->enemies = new_enemies(pos);
	else
	{
		new = new_enemies(pos);
		add_enemies(&data->enemies, new);
	}
}
