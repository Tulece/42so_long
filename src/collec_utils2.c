/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:31:18 by anporced          #+#    #+#             */
/*   Updated: 2024/02/06 20:31:50 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_collectibles	*find_by_pos(t_data *data, t_axes pos)
{
	t_collectibles	*collec;

	collec = data->collectibles;
	while (collec)
	{
		if (collec->c_pos.x == pos.x && collec->c_pos.y == pos.y)
			return (collec);
		collec = collec->next;
	}
	return (NULL);
}

void	delete_collec_by_pos(t_data *data, t_axes pos)
{
	t_collectibles	*current;
	t_collectibles	*prev;

	current = data->collectibles;
	prev = NULL;
	if (current != NULL && current->c_pos.x == pos.x
		&& current->c_pos.y == pos.y)
	{
		data->collectibles = current->next;
		free(current);
		return ;
	}
	while (current != NULL && (current->c_pos.x != pos.x
			|| current->c_pos.y != pos.y))
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	free(current);
}
