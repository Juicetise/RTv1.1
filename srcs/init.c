/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:40:52 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:40:54 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		init_sdl(t_general *all)
{
	if (SDL_Init(SDL_INIT_EVENTS) == -1)
		return (0);
	if (!(all->wn =\
	SDL_CreateWindow("RTv1", 0, 0, all->width, all->height, 0)))
		return (0);
	all->pixels = SDL_GetWindowSurface(all->wn)->pixels;
	return (1);
}

void	init(t_general *all, char *str)
{
	all->cam_pos.x = 0;
	all->cam_pos.y = 0;
	all->cam_pos.z = 0;
	all->cam_dir.x = 0;
	all->cam_dir.y = 0;
	all->cam_dir.z = 1;
	all->run = 1;
	all->width = 800;
	all->height = 800;
	all->xspot = 0;
	init_tab_obj(all, str);
	if (!(all->key = SDL_GetKeyboardState(NULL)))
		return ;
}
