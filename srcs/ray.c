/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:42:47 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:42:48 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	draw(t_general *all)
{
	int	x;
	int	y;
	int	id;

	id = 0;
	y = 0;
	while (y < all->height)
	{
		x = 0;
		while (x < all->width)
		{
			init_ray(all, x, y);
			id = intersection(all);
			if (id > 0 && id <= all->obj_nb)
				lambert(all, x, y, id);
			else
				pxl2img(all, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	init_ray(t_general *all, int x, int y)
{
	all->mm.x = x - (all->width / 2);
	all->mm.y = y - (all->height / 2);
	all->mm.z = -(all->width / -1.5);
	ft_vectornorm(&all->mm);
	all->ray_dir.x = all->mm.x - all->cam_pos.x;
	all->ray_dir.y = all->mm.y - all->cam_pos.y;
	all->ray_dir.z = all->mm.z - all->cam_pos.z;
	ft_vectornorm(&all->ray_dir);
	all->oray.x = all->cam_pos.x;
	all->oray.y = all->cam_pos.y;
	all->oray.z = all->cam_pos.z;
	all->dray.x = all->ray_dir.x;
	all->dray.y = all->ray_dir.y;
	all->dray.z = all->ray_dir.z;
}
