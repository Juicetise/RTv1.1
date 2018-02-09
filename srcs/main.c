/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:50:39 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:50:44 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			rgb2hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		pxl2img(t_general *all, int x, int y, int color)
{
	all->pixels[(int)(all->width) * y + x] = color;
}

void		free_for_all(t_general *all)
{
	SDL_DestroyWindow(all->wn);
	free(all);
	exit(1);
}

static int	global_loop(t_general *all)
{
	while (all->run)
	{
		SDL_PollEvent(&all->event);
		all->key = SDL_GetKeyboardState(NULL);
		if (all->event.type == 256)
			free_for_all(all);
		if (all->event.window.type == SDL_WINDOWEVENT_CLOSE
			|| all->event.key.keysym.sym == SDLK_ESCAPE
			|| all->event.type == SDL_QUIT)
			free_for_all(all);
		if (!all->finished)
			draw(all);
		SDL_UpdateWindowSurface(all->wn);
		all->key = SDL_GetKeyboardState(NULL);
	}
	free_for_all(all);
	return (0);
}

int			main(int argc, char **argv)
{
	t_general	*all;

	if (argc == 2)
	{
		all = (t_general *)malloc(sizeof(t_general));
		init(all, argv[1]);
		init_sdl(all);
		global_loop(all);
	}
	return (0);
}
