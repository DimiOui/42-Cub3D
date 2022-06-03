/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimi <dimi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:36:46 by jsemel            #+#    #+#             */
/*   Updated: 2022/06/02 17:03:02 by dimi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_pressed(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.move_direction = 'w';
	else if (keycode == A)
		game->player.move_direction = 'a';
	else if (keycode == S)
		game->player.move_direction = 's';
	else if (keycode == D)
		game->player.move_direction = 'd';
	else if (keycode == L_ARROW)
		game->player.turn_direction = -1;
	else if (keycode == R_ARROW)
		game->player.turn_direction = 1;
	else if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
		mlx_destroy_display(game->mlx.mlx_ptr);
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

static int	key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		game->player.move_direction = 0;
	else if (keycode == L_ARROW || keycode == R_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

static int	close_window_cross(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free_game(game);
	exit(EXIT_SUCCESS);
	return (1);
}

void	init_hooks(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win, KEY_PRESS, M_KEY_PRESS, key_pressed, game);
	mlx_hook(game->mlx.win, KEY_RELEASE, M_KEY_RELEASE, key_released, game);
	mlx_hook(game->mlx.win,
		CROSS_DESTROY,
		M_DESTROY,
		close_window_cross,
		game);
}
