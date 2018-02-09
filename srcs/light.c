/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:41:16 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:41:25 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	light(t_general *all, float d, float lambert)
{
	lambert = ft_clamp(lambert * 4.0 * d, 0.0, 1.0);
	all->finalcolor.r = lambert *
		((all->objcolor.r / 255) * (all->spot->color.r / 255)) * 255;
	all->finalcolor.g = lambert *
		((all->objcolor.g / 255) * (all->spot->color.g / 255)) * 255;
	all->finalcolor.b = lambert *
		((all->objcolor.b / 255) * (all->spot->color.b / 255)) * 255;
	all->finalcolor.r = ft_clamp(all->finalcolor.r, 0, 255);
	all->finalcolor.g = ft_clamp(all->finalcolor.g, 0, 255);
	all->finalcolor.b = ft_clamp(all->finalcolor.b, 0, 255);
}

int		ft_shadow(t_general *all, t_vec pos, int id)
{
	t_vec	dist2;
	int		i;
	int u;

	u = id;
	i = 1;
	dist2 = ft_vectorsub(&all->spot->pos, &pos);
	all->t = sqrtf(ft_vectordot(&dist2, &dist2));
	ft_vectornorm(&dist2);
	while (i <= all->obj_nb)
	{
		//if (i != id)
		//{
			if (all->tab_obj[i]->type == 1)
				all->a = inter_plane(all, dist2, pos, i);
			else if (all->tab_obj[i]->type == 2)
				all->a = inter_sphere(all, dist2, pos, i) + 1;
			else if (all->tab_obj[i]->type == 3)
				all->a = inter_cone(all, dist2, pos, i) + 0.1;
			else if (all->tab_obj[i]->type == 4)
				all->a = inter_cylinder(all, dist2, pos, i) + 1;
			if (all->a > 0.001 && all->a <= all->t)
				return (1);
		//}
		i++;
	}
	return (0);
}

void	lambert(t_general *all, int x, int y, int id)
{
	t_vec position;
	t_vec dist;
	float d;
	float lambert;

	position.x = all->oray.x + all->t * all->dray.x;
	position.y = all->oray.y + all->t * all->dray.y;
	position.z = all->oray.z + all->t * all->dray.z;
	all->norm = norm(all, position, id);
	lambert = 2;
	dist = ft_vectorsub(&all->spot->pos, &position);
	d = ft_clamp((1.0 / sqrtf(sqrtf(ft_vectordot(&dist, &dist)))), 0., 1.);
	ft_vectornorm(&dist);
	if (ft_shadow(all, position, id) == 0)
	{
		lambert += ft_clamp(ft_vectordot(&dist, &all->norm), 0.0, 1.0);
		light(all, d, lambert);
		create_pixel(all, x, y, 0);
	}
	else if (ft_shadow(all, position, id) == 1)
	{
		lambert += ft_clamp(ft_vectordot(&dist, &all->norm), 0.0, 1.0);
		light(all, d, lambert);
		create_pixel(all, x, y, 1);
	}
}

void	create_pixel(t_general *all, int x, int y, int shadow)
{
	if (shadow == 0)
	{
		pxl2img(all, x, y, (((int)(all->finalcolor.r) & 0xff) << 16) +
			(((int)(all->finalcolor.g) & 0xff) << 8) +
			((int)(all->finalcolor.b) & 0xff));
	}
	if (shadow == 1)
	{
		all->colortampon = (((int)(all->finalcolor.r) & 0xff) << 16) +
			(((int)(all->finalcolor.g) & 0xff) << 8) +
			((int)(all->finalcolor.b) & 0xff);
		all->colortampon = (all->colortampon >> 1) & 8355711;
		pxl2img(all, x, y, all->colortampon);
	}
}
