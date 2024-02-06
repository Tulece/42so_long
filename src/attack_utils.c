/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:52:52 by anporced          #+#    #+#             */
/*   Updated: 2024/01/24 15:04:11 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	get_color(int state)
{
	unsigned int	color;

	color = 0;
	if (state == 1)
		color = RED;
	else if (state == 2)
		color = BLUE;
	else if (state == 3)
		color = YELLOW;
	else if (state == 4)
		color = BLACK;
	else if (state == 5)
		color = PURPLE;
	else if (state == 6)
		color = ICE_BLUE;
	else if (state == 7)
		color = GREEN;
	return (color);
}

void	display_attack(t_data *data)
{
	t_axes	attack_pos;

	attack_pos = find_dir(data->player.p_pos, data->player.direction);
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
	overlay_attack
		(data, attack_pos, get_color(data->player.state));
}
