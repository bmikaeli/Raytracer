/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:34:51 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 14:10:21 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"


t_scene		*new_scene(void)
{
	t_scene	*new;

	new = NEW(t_scene);
	new->tab_s = NULL;
	new->count_s = 0;
	new->tab_p = NULL;
	new->count_p = 0;
	return (new);
}
# include <stdio.h>
t_scene		*add_sphere(t_scene *rob, t_sphere *new)
{
	t_sphere	**tab;
	int			i;

	i = 0;
	rob->count_s += 1;
	tab = (t_sphere**)malloc(rob->count_s * sizeof(t_sphere*));
	while (i != (rob->count_s - 1))
	{
		tab[i] = rob->tab_s[i];
		i++;
	}
	tab[i] = new;
	free(rob->tab_s);
	rob->tab_s = tab;
	return (rob);
}

t_scene		*add_light(t_scene *rob, t_light *new)
{
	t_light	**tab;
	int			i;

	i = 0;
	rob->count_l += 1;

	tab = (t_light**)malloc(rob->count_l * sizeof(t_light*));
	while (i != (rob->count_l - 1))
	{
		tab[i] = rob->tab_l[i];
		i++;
	}
	tab[i] = new;
	free(rob->tab_l);
	rob->tab_l = tab;

	return (rob);
}

t_scene		*add_plan(t_scene *rob, t_plan *new)
{
	t_plan		**tab;
	int			i;

	i = 0;
	rob->count_p += 1;
	tab = (t_plan**)malloc(rob->count_p * sizeof(t_plan*));
	while (i < (rob->count_p - 1))
	{
		tab[i] = rob->tab_p[i];
		i++;
	}
	tab[i] = new;
	free(rob->tab_p);
	rob->tab_p = tab;
	return (rob);
}

t_scene		*add_cyl(t_scene *rob, t_cyl *cyl)
{
	t_cyl		**tab;
	int			i;

	i = 0;
	rob->count_cyl += 1;
	tab = (t_cyl**)malloc(rob->count_cyl * sizeof(t_cyl*));
	while (i < (rob->count_cyl - 1))
	{
		tab[i] = rob->tab_cyl[i];
		i++;
	}
	tab[i] = cyl;
	free(rob->tab_cyl);
	rob->tab_cyl = tab;
	return (rob);
}
