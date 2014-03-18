/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:41:32 by tdemay            #+#    #+#             */
/*   Updated: 2014/01/29 17:41:32 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "libft/libft.h"
# include "list.h"

typedef struct	s_cam
{
	int		x;
	int		y;
	int		z;
}				t_cam;

typedef struct	s_view
{
	float	vp_width;
	float	vp_height;
	float	vp_dist;
	float	vp_start;
}				t_view;

typedef struct	s_env
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	char	*name;
	t_view	*vp;
	t_cam	*cam;
}				t_env;

void	parse_file(t_env *e, t_lst *lst, char *file);

#endif /* !PARSER_H */
