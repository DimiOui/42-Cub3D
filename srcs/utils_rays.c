/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:49 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/06/01 14:42:39 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map *map, double x, double y, t_ray *ray)
{
	ray->x = x;
	ray->y = y;
	if ((int)x < 0 || map->width < (int)x || (int)y < 0 || map->height < (int)y)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->height == (int)y)
	{
		ray->w_block = '1';
		ray->orientation = 'N';
		return (1);
	}
	ray->w_block = map->matrix[(int)y][(int)x];
	if (ray->w_block == '1')
	{
		ray->orientation = wall_facing(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}

char	wall_facing(t_map *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'X')
	{
		if (map->matrix[y - 1][x] != '1' && south_facing(ray->angle))
			return ('N');
		else if (map->matrix[y + 1][x] != '1' && !south_facing(ray->angle))
			return ('S');
	}
	else
	{
		if (map->matrix[y][x - 1] != '1' && !west_facing(ray->angle))
			return ('W');
		else if (map->matrix[y][x + 1] != '1' && west_facing(ray->angle))
			return ('E');
	}
	return (0);
}

int	south_facing(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

int	west_facing(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}
