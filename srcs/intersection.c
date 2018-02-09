/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:41:04 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:41:06 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

float	inter_cylinder(t_general *all, t_vec ray, t_vec pos, int i)
{
	float	disc;

	all->dist = ft_vectorsub(&pos, &all->tab_obj[i]->pos);
	ft_vectornorm(&all->tab_obj[i]->rot);
	all->a = ft_vectordot(&ray, &ray) -
		pow(ft_vectordot(&ray, &all->tab_obj[i]->rot), 2);
	all->b = 2 * (ft_vectordot(&ray, &all->dist) -
		(ft_vectordot(&ray, &all->tab_obj[i]->rot) *
		ft_vectordot(&all->dist, &all->tab_obj[i]->rot)));
	all->c = ft_vectordot(&all->dist, &all->dist) -
		pow(ft_vectordot(&all->dist, &all->tab_obj[i]->rot), 2) -
		pow(all->tab_obj[i]->size, 2);
	disc = all->b * all->b - 4 * all->a * all->c;
	if (disc < 0)
		return (80000.0);
	all->t0 = (-all->b + sqrtf(disc)) / (2 * all->a);
	all->t1 = (-all->b - sqrtf(disc)) / (2 * all->a);
	if (all->t0 > all->t1)
		all->t0 = all->t1;
	return (all->t0);
}

float	inter_cone(t_general *all, t_vec ray, t_vec pos, int i)
{
	float	disc;

	all->dist = ft_vectorsub(&pos, &all->tab_obj[i]->pos);
	ft_vectornorm(&all->tab_obj[i]->rot);
	all->a = ft_vectordot(&ray, &ray) -
		(1 + pow(tan(all->tab_obj[i]->size), 2)) *
		pow(ft_vectordot(&ray, &all->tab_obj[i]->rot), 2);
	all->b = 2 * (ft_vectordot(&ray, &all->dist) -
		(1 + pow(tan(all->tab_obj[i]->size), 2))
		* ft_vectordot(&ray, &all->tab_obj[i]->rot) *
		ft_vectordot(&all->dist, &all->tab_obj[i]->rot));
	all->c = ft_vectordot(&all->dist, &all->dist) -
		(1 + pow(tan(all->tab_obj[i]->size), 2)) *
		pow(ft_vectordot(&all->dist, &all->tab_obj[i]->rot), 2);
	disc = all->b * all->b - 4 * all->a * all->c;
	if (disc < 0)
		return (80000.0);
	all->t0 = (-all->b + sqrtf(disc)) / (2 * all->a);
	all->t1 = (-all->b - sqrtf(disc)) / (2 * all->a);
	if (all->t0 > all->t1)
		all->t0 = all->t1;
	return (all->t0);
}

float	inter_sphere(t_general *all, t_vec ray, t_vec pos, int i)
{
	float disc;

	all->dist = ft_vectorsub(&pos, &all->tab_obj[i]->pos);
	all->a = ft_vectordot(&ray, &ray);
	all->b = 2 * ft_vectordot(&ray, &all->dist);
	all->c = ft_vectordot(&all->dist, &all->dist) -
		(all->tab_obj[i]->size * all->tab_obj[i]->size);
	disc = all->b * all->b - 4 * all->a * all->c;
	if (disc < 0)
		return (-1);
	all->t0 = (-all->b + sqrtf(disc)) / (2 * all->a);
	all->t1 = (-all->b - sqrtf(disc)) / (2 * all->a);
	if (all->t0 > all->t1)
		all->t0 = all->t1;
	return (all->t0);
}

float	inter_plane(t_general *all, t_vec ray, t_vec pos, int i)
{
	if (ft_vectordot(&all->tab_obj[i]->rot, &ray) != 0)
		all->t0 = ((ft_vectordot(&all->tab_obj[i]->rot, &all->tab_obj[i]->pos) -
			ft_vectordot(&all->tab_obj[i]->rot, &pos)) /
			ft_vectordot(&all->tab_obj[i]->rot, &ray));
	if (all->t0 < 0.0001)
		return (-1);
	return (all->t0);
}

int		intersection(t_general *all)
{
	float	dist;
	int		i;
	int		tmp;

	i = 0;
	all->t = 80000.0;
	while (i++ < all->obj_nb)
	{
		all->t0 = -1;
		all->t1 = -1;
		if (all->tab_obj[i]->type == 1)
			dist = inter_plane(all, all->dray, all->oray, i);
		else if (all->tab_obj[i]->type == 2)
			dist = inter_sphere(all, all->dray, all->oray, i);
		else if (all->tab_obj[i]->type == 3)
			dist = inter_cone(all, all->dray, all->oray, i);
		else if (all->tab_obj[i]->type == 4)
			dist = inter_cylinder(all, all->dray, all->oray, i);
		if (dist > 0.0001 && dist < all->t)
		{
			tmp = i;
			all->t = dist;
		}
	}
	return (tmp);
}
