/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:11:55 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 05:15:58 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init_tab_obj(t_general *all, char *src)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	line = NULL;
	if ((fd = open(src, O_RDONLY)) <= 0)
		free_for_all(all);
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	all->obj_nb = ft_atoi(tab[0]);
	all->spot_nb = 1;
	if (all->obj_nb == 0 || all->spot_nb == 0)
		free_for_all(all);
	i = 0;
	all->tab_obj = malloc(sizeof(t_obj*) * (all->obj_nb + 1));
	all->spot = malloc(sizeof(t_spot) * (all->spot_nb + 1));
	while (get_next_line(fd, &line) > 0)
	{
		if ((tab = ft_strsplit(line, ' ')))
			add_obj_to_tab(all, tab, i++);
	}
	if (i != (all->obj_nb + all->spot_nb))
		free_for_all(all);
	ft_freetab(tab);
	free(line);
}

void	add_obj_to_tab(t_general *all, char **tab, int i)
{
	t_obj	*obj;

	if (tab && !ft_strcmp(tab[0], "Spot"))
	{
		if (all->xspot == 1)
			free_for_all(all);
		add_spot(all, tab);
		all->xspot = 1;
		return ;
	}
	if (!tab || ft_tablen((void**)tab) < 10)
		free_for_all(all);
	obj = ft_memalloc(sizeof(t_obj));
	obj->pos.x = ft_atof(tab[1]);
	obj->pos.y = ft_atof(tab[2]);
	obj->pos.z = ft_atof(tab[3]);
	obj->rot.x = ft_atof(tab[4]);
	obj->rot.y = ft_atof(tab[5]);
	obj->rot.z = ft_atof(tab[6]);
	obj->color.r = ft_atof(tab[7]);
	obj->color.g = ft_atof(tab[8]);
	obj->color.b = ft_atof(tab[9]);
	obj->size = ft_atof(tab[10]);
	select_type(tab, obj);
	all->tab_obj[i] = obj;
}

void	select_type(char **tab, t_obj *obj)
{
	if (!ft_strcmp(tab[0], "Sphere"))
		obj->type = 2;
	else if (!ft_strcmp(tab[0], "Plane"))
		obj->type = 1;
	else if (!ft_strcmp(tab[0], "Cone"))
		obj->type = 3;
	else if (!ft_strcmp(tab[0], "Cylinder"))
		obj->type = 4;
}

void	add_spot(t_general *all, char **tab)
{
	if (ft_tablen((void**)tab) < 6)
		free_for_all(all);
	all->spot->pos.x = ft_atof(tab[1]);
	all->spot->pos.y = ft_atof(tab[2]);
	all->spot->pos.z = ft_atof(tab[3]);
	all->spot->color.r = ft_atof(tab[4]);
	all->spot->color.g = ft_atof(tab[5]);
	all->spot->color.b = ft_atof(tab[6]);
}
