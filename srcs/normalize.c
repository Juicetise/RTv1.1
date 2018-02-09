/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:25:19 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 02:25:21 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec	norm_plane(t_general *all, int id)
{
	t_vec	norm;

	norm = all->tab_obj[id]->rot;
	all->objcolor.r = all->tab_obj[id]->color.r;
	all->objcolor.g = all->tab_obj[id]->color.g;
	all->objcolor.b = all->tab_obj[id]->color.b;
	return (norm);
}

t_vec	norm_sphere(t_general *all, t_vec pos, int id)
{
	t_vec	norm;

	norm = ft_vectorsub(&pos, &all->tab_obj[id]->pos);
	all->objcolor.r = all->tab_obj[id]->color.r;
	all->objcolor.g = all->tab_obj[id]->color.g;
	all->objcolor.b = all->tab_obj[id]->color.b;
	return (norm);
}

t_vec	norm_cone(t_general *all, t_vec pos, int id)
{
	t_vec	norm;
	t_vec	temp;
	t_vec	temp2;

	temp = ft_vectorscale(&all->tab_obj[id]->rot,
		(ft_vectordot(&all->dray, &all->tab_obj[id]->rot) *
		all->t + ft_vectordot(&all->dist, &all->tab_obj[id]->rot)));
	temp = ft_vectorscale(&temp, (1 + pow(tan(all->tab_obj[id]->size), 2)));
	temp2 = ft_vectorsub(&pos, &all->tab_obj[id]->pos);
	norm = ft_vectorsub(&temp2, &temp);
	all->objcolor.r = all->tab_obj[id]->color.r;
	all->objcolor.g = all->tab_obj[id]->color.g;
	all->objcolor.b = all->tab_obj[id]->color.b;
	return (norm);
}

t_vec	norm_cylinder(t_general *all, t_vec pos, int id)
{
	t_vec	norm;
	t_vec	temp;
	t_vec	temp2;

	temp = ft_vectorscale(&all->tab_obj[id]->rot,
		(ft_vectordot(&all->dray, &all->tab_obj[id]->rot) *
		all->t + ft_vectordot(&all->dist, &all->tab_obj[id]->rot)));
	temp2 = ft_vectorsub(&pos, &all->tab_obj[id]->pos);
	norm = ft_vectorsub(&temp2, &temp);
	all->objcolor.r = all->tab_obj[id]->color.r;
	all->objcolor.g = all->tab_obj[id]->color.g;
	all->objcolor.b = all->tab_obj[id]->color.b;
	return (norm);
}

t_vec	norm(t_general *all, t_vec pos, int id)
{
	t_vec	norm;

	if (all->tab_obj[id]->type == 1)
		norm = norm_plane(all, id);
	else if (all->tab_obj[id]->type == 2)
		norm = norm_sphere(all, pos, id);
	else if (all->tab_obj[id]->type == 3)
		norm = norm_cone(all, pos, id);
	else if (all->tab_obj[id]->type == 4)
		norm = norm_cylinder(all, pos, id);
	ft_vectornorm(&norm);
	return (norm);
}
