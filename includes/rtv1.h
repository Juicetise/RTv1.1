/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:50:36 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 02:50:40 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define FOV 45

typedef struct		s_color
{
	float		r;
	float		g;
	float		b;
}					t_color;

typedef struct		s_vec
{
	float		x;
	float		y;
	float		z;
}					t_vec;

typedef struct		s_spot
{
	t_vec		pos;
	t_color		color;
}					t_spot;

typedef struct		s_obj
{
	int			type;
	float		size;
	t_vec		rot;
	t_vec		pos;
	t_color		color;
}					t_obj;

typedef struct		s_general
{
	int			height;
	int			width;
	void		*mx;
	SDL_Window	*wn;
	void		*img;
	char		*argv;
	int			bpp;
	int			len;
	int			endian;
	char		*data;
	SDL_Texture	*texture;
	int			*pixels;
	const Uint8	*key;
	char		run;
	SDL_Event	event;
	t_vec		i;
	t_vec		j;
	t_vec		k;
	t_vec		cam_pos;
	t_vec		cam_dir;
	t_vec		ray_dir;
	t_vec		norm;
	float		normraydist;
	t_vec		dist;
	t_vec   raylightdist;
	t_vec		raylightdir;
	t_vec		intensitylight;
	t_obj		plan;
	t_obj		sphere;
	t_obj		light;
	t_obj		cone;
	t_obj		cylinder;
	t_color		objcolor;
	t_color		finalcolor;
	t_obj		**tab_obj;
	t_spot		*spot;
	float		t0;
	float		t1;
	float		t;
	float		d1;
	float		d2;
	float		d3;
	float		a;
	float		b;
	float		c;
	float		lambert;
	int			type;
	int			colortampon;
	t_vec		mm;
	t_vec		oray;
	t_vec		dray;
	int			obj_nb;
	int			spot_nb;
	int			xspot;
	int 		finished;
}					t_general;

float		inter_cylinder(t_general *all, t_vec ray, t_vec pos, int i);
float		inter_cone(t_general *all, t_vec ray, t_vec pos, int i);
float		inter_plane(t_general *all, t_vec ray, t_vec pos, int i);
float		inter_sphere(t_general *all, t_vec ray, t_vec pos, int i);
void		init_tab_obj(t_general *all, char *src);
void		add_obj_to_tab(t_general *all, char **tab, int i);
void		select_type(char **tab, t_obj *obj);
void		add_spot(t_general *all, char **tab);
int		ft_freetab(char **tab);
float		ft_atof(const char *str);
void		free_for_all(t_general *all);
size_t		ft_tablen(void **tab);
int		rgb2hex(int r, int g, int b);
void		pxl2img(t_general *all, int x, int y, int color);
int		init_sdl(t_general *all);
void		init(t_general *all, char *str);
int		intersection(t_general *all);
void		light(t_general *all, float d, float lambert);
int		ft_shadow(t_general *all, t_vec pos, int id);
void		lambert(t_general *all, int x, int y, int id);
void		draw(t_general *all);
void		init_ray(t_general *all, int x, int y);
t_vec		ft_vectorscale(t_vec *v, float n);
t_vec		ft_vectorsub(t_vec *v1, t_vec *v2);
t_vec		ft_vectorcross(t_vec *v1, t_vec *v2);
void		ft_vectornorm(t_vec *v);
t_vec 	ft_vectormul(t_vec *v1, t_vec *v2);
float		ft_vectordot(t_vec *v1, t_vec *v2);
t_vec		norm(t_general *all, t_vec pos, int id);
void		create_pixel(t_general *all, int x, int y, int shadow);

#endif
