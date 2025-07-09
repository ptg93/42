/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:36:45 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/07/09 11:36:46 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_update(t_map *map)
{
	draw_map(map);
	display_score(map);
	if (map->game_over)
		check_game_over(map->game_over, map);
}
