/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:18:28 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 14:10:27 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

/*
** \fn		void	raytrace(int x, int y, t_env *e)
** \brief	raytrace pour un pixel
** \author	tdemay
**
** \param	x : pixel sur la largeur
** \param	y : pixel sur la hauteur
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
**
** Raytracing sur un pixel avec calcul de normal sur vecteur et
** parcours de tous les éléments de la scene grace a parse_element()
*/
void			raytrace(int x, int y, t_env *e)
{
	float	xnorm;
	float	ynorm;
	float	pointx;
	float	pointy;
	t_vect	*point;

	xnorm = (x + 0.5) / SWIDTH;
	ynorm = (y + 0.5) / SHEIGHT;
	pointx = (2 * xnorm - 1) * (SWIDTH / SHEIGHT) * e->cam->FOV;
	pointy = (1 - 2 * ynorm) * e->cam->FOV;
	point = new_vect(pointx, pointy, -1);
	mlx_pixel_put(e->mlx, e->win, x, y, COLOR(parse_element(e, point)));
}

/*
** \fn		static int		expose_hook(t_env *e)
** \brief	fonction appele lors du chargement de la fenetre
** \author	tdemay
**
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
**
** Parcours tout les pixels en hauteur et largeur pour raytrace
** chaque pixel.
*/
static int		expose_hook(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	add_light(e->s, make_light(new_vect(0, 0, -30), new_color(255, 0, 0)));
	add_light(e->s, make_light(new_vect(10, 0, -30), new_color(0, 255, 0)));
	add_light(e->s, make_light(new_vect(-10, 0, -30), new_color(0, 0, 255)));
	while (y++ < SHEIGHT)
	{
		x = 0;
		while (x++ < SWIDTH)
			raytrace(x, y, e);
	}
	return (0);
}

/*
** \fn		static int		key_hook(int keycode, t_env *e)
** \brief	fonction appele lors d'un appui de touche
** \author	tdemay
**
** \param	keycode : le code touche appuyé
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
**
** Permet de fermer le programme si on appuye sur la touche echap
*/
static int		key_hook(int keycode, t_env *e)
{
	(void) e;

	if (keycode == ECHAP)
		exit(0);
	return (0);
}

/*
** \fn		int				main(void)
** \brief	fonction principal
** \author	tdemay
**
** Initialisation des objets de t_env, l'objet camera,
** l'objet scene et l'ajout des objets dans la scene.
** l'objet mlx et win associer a la minilibx.
** Et creation de la fenetre.
*/
int				main(void)
{
	t_env		e;

	e.cam = cam_init();
	e.mlx = mlx_init();
	e.s = new_scene();
	// e.s = add_cyl(e.s, new_cyl(1050, 1000, -200, 1, 0xff0080));
	e.s = add_sphere(e.s, new_sphere(0, -30, -50, 10, new_color(200, 0, 0)));
	e.s = add_sphere(e.s, new_sphere(-30, 0, -50, 10, new_color(0, 200, 0)));
	e.s = add_sphere(e.s, new_sphere(30, 0, -50, 10, new_color(0, 0, 200)));
	e.s = add_sphere(e.s, new_sphere(0, 0, -50, 10, new_color(50, 60, 50)));
	e.s = add_sphere(e.s, new_sphere(0, 30, -50, 10, new_color(200, 200, 200)));
	// e.s = add_plan(e.s, new_plan(new_vect(0, 0, -40), new_vect(0, 1, 1), new_color(0, 255, 255)));
	e.win = mlx_new_window(e.mlx, SWIDTH, SHEIGHT, "Raytrace");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
