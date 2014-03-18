/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:58:09 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 14:08:19 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

float		parse_sphere(t_env *e, t_vect *point, t_color **color, int z)
{
	float	tmp;
	float	dist;
	float	dp;
	int		i;
	t_vect	*dir;
	t_vect	*test;
	t_color *color_tmp;

	color_tmp = NEW(t_color);

	i = 0;
	dist = -1;
	while (i < e->s->count_s)
	{
		tmp = intersect_sphere(point, e->cam, e->s->tab_s[i]);
		if (tmp > 0 && (dist == -1 || dist > tmp))
		{
			dist = tmp;
			*color = cpy_color(e->s->tab_s[i]->color);
			*color_tmp = *cpy_color(sub_colour(*color, e->s->tab_l[z]->clr));
			*color_tmp = *cpy_color(sub_colour(color_tmp, e->s->tab_l[z]->clr));
			*color = cpy_color(color_tmp);
			dir =  SUB(e->s->tab_l[z]->pos, ADD(e->cam->pos, MULTC(point, tmp)));
			test = SUB(e->s->tab_s[i]->pos, ADD(e->cam->pos, MULTC(point, tmp)));
			vector_normalize(dir);
			vector_normalize(test);
			dp =  -DOTPROD(dir, test);
			mult(*color, MAX(dp, 0));
		}
		i++;
	}
	return (dist);
}

float		parse_plan(t_env *e, t_vect *point, t_color **color)
{
	float	tmp;
	float	dist;
	float	dp;
	int		i;
	t_vect	*dir;
	t_vect	*test;

	i = 0;
	dist = -1;
	while (i < e->s->count_p)
	{
		tmp = intersect_plan(point, e->cam, e->s->tab_p[i]);
		if (tmp > 0 && (dist == -1 || dist > tmp))
		{
			dist = tmp;
			*color = cpy_color(e->s->tab_p[i]->color);
			dir =  SUB(e->l[0]->pos, ADD(e->cam->pos, MULTC(point, tmp)));
			test = SUB(e->s->tab_p[i]->pos, ADD(e->cam->pos, MULTC(point, tmp)));
			vector_normalize(dir);
			vector_normalize(test);
			dp = 50 / tmp * DOTPROD(dir, test);
			mult(*color, MAX(dp, 0));
		}
		i++;
	}
	return (dist);
}

float		parse_cylinder(t_env *e, t_vect *point, t_color **color)
{
	float	tmp;
	float	dist;
	int		i;
	// t_vect	*dir;
	// t_vect	*test;
	// float	dp;

	i = 0;
	dist = -1;
	while (i < e->s->count_cyl)
	{
		tmp = intersect_cyl(point, e->cam->pos, e->s->tab_cyl[i]);
		if (tmp > 0 && (dist == -1 || dist > tmp))
		{
			dist = tmp;
			*color = e->s->tab_cyl[i]->color;
			// dir = SUB(e->l->pos, ADD(e->cam->pos, MULTC(point, tmp)));
			// test =(SUB(e->s->tab_cyl[i]->pos, ADD(e->cam->pos, MULTC(point, tmp))));
			// vector_normalize(dir);
			// //vector_normalize(test);
			// dp = 0.0001 * DOTPROD(dir, test);
			// mult(color, dp);
		}
		i++;
	}
	return (dist);
}
//back_up

// t_color		*parse_element(t_env *e, t_vect *point)
// {
// 	t_color	*color;
// 	float	dist;
// 	float	tmp;
// 	t_color	*tmp_c;

// 	color = new_color(255, 255, 255);
// 	tmp_c = new_color(255, 255, 255);
// 	dist = -1;
// 	if (e->s->count_s)
// 	{
// 		tmp = parse_sphere(e, point, &tmp_c);
// 		if (tmp > 0 && (dist == -1 || dist > tmp))
// 		{
// 			dist = tmp;
// 			color = tmp_c;
// 			// printf("tmp sphere: %lf\n", tmp);
// 		}
// 	}
// 	if (e->s->count_cyl)
// 	{
// 		tmp = parse_cylinder(e, point, &tmp_c);
// 		if (tmp != -1 && (dist == -1 || dist > tmp))
// 		{
// 			dist = tmp;
// 			color = tmp_c;
// 		}
// 		// printf("tmp cyl: %lf\n", tmp);
// 	}
// 	if (e->s->count_p)
// 	{
// 		tmp = parse_plan(e, point, &tmp_c);
// 		if (tmp > 0 && (dist == -1 || dist > tmp))
// 		{
// 			dist = tmp;
// 			color = tmp_c;
// 		}
// 		//printf("tmp plan: %lf\n", tmp);
// 	}
// 	return (color);
// }

t_color		*parse_element(t_env *e, t_vect *point)
{
	t_color		*color;
	float		dist;
	float		tmp;
	t_color		*tmp_c;
	int			i;

	i = 0;
	color = new_color(255, 255, 255);
	tmp_c = new_color(255, 255, 255);
	dist = -1;
	while(i < e->s->count_l)
	{
		if (e->s->count_s)
		{
			tmp = parse_sphere(e, point, &tmp_c, i);
			color = add_colour(color, tmp_c);
			if (tmp > 0 && (dist == -1 || dist > tmp))
			{
				dist = tmp;
				color = tmp_c;
				// printf("tmp sphere: %lf\n", tmp);
			}
		}
		if (e->s->count_cyl)
		{
			tmp = parse_cylinder(e, point, &tmp_c);
			if (tmp != -1 && (dist == -1 || dist > tmp))
			{
				dist = tmp;
				color = tmp_c;
			}
			// printf("tmp cyl: %lf\n", tmp);
		}
		if (e->s->count_p)
		{
			tmp = parse_plan(e, point, &tmp_c);
			if (tmp > 0 && (dist == -1 || dist > tmp))
			{
				dist = tmp;
				color = tmp_c;
			}
			//printf("tmp plan: %lf\n", tmp);
		}
		i++;

	}

	return (color);
}
