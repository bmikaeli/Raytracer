/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:40:27 by tdemay            #+#    #+#             */
/*   Updated: 2014/01/29 17:40:27 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		get_object(int fd, t_lst *root)
{
	t_lst	*ret;
	void	*obj;
	int		finish;
	char	*line;
	char	**get;

	finish = 1;
	ret = NEW(t_lst);
	while (finish && get_next_line(fd, &line) > 0)
	{
		get = ft_strsplit(line, ' ');
		if (ft_strstr(line, "type:"))
			ret->type = get[1];
		else if (ft_strstr(line, "x:"))
			ret->x = ft_atoi(get[1]);
		else if (ft_strstr(line, "y:"))
			ret->y = ft_atoi(get[1]);
		else if (ft_strstr(line, "z:"))
			ret->z = ft_atoi(get[1]);
		if (ft_strlen(line) == 0)
			finish = 0;
	}
	//obj = create_obj();
	add_t_lst(root, ret->type, obj, ret->x, ret->y, ret->z);
}

void		get_scene(int fd, t_env *e)
{
	int		finish;
	char	*line;
	char	**get;

	finish = 1;
	while (finish && get_next_line(fd, &line) > 0)
	{
		get = ft_strsplit(line, ' ');
		if (ft_strstr(line, "name:"))
			e->name = ft_strjoin("RT_V1 : ", get[1]);
		else if (ft_strstr(line, "width:"))
			e->width = ft_atoi(get[1]);
		else if (ft_strstr(line, "height:"))
			e->height = ft_atoi(get[1]);
		else if (ft_strstr(line, "x:"))
			e->cam->x = ft_atoi(get[1]);
		else if (ft_strstr(line, "y:"))
			e->cam->y = ft_atoi(get[1]);
		else if (ft_strstr(line, "z:"))
			e->cam->z = ft_atoi(get[1]);
		if (ft_strlen(line) == 0)
			finish = 0;
	}
}

void		parse_file(t_env *e, t_lst *lst, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "scene:"))
			get_scene(fd, e);
		else if (ft_strstr(line, "object:"))
			get_object(fd, lst);
	}
}
