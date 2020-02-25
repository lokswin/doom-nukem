/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_map_sector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:06:08 by dorange-          #+#    #+#             */
/*   Updated: 2020/02/21 20:23:28 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_me_get_sector_status(t_list *list)
{
	t_sector	*s;

	s = list->content;
}

/*
** **************************************************************************
**	void ft_editor_sector_create(t_wolf3d *w)
**
**	Function that create sector.
** **************************************************************************
*/

void		ft_editor_sector_create(t_wolf3d *w)
{
	t_sector	sector;
	t_list		*list_item;

	sector.id = w->sector_count + 1;
	sector.vertex = NULL;
	sector.neighbors = NULL;
	sector.vertex_count = 0;
	sector.status = SECTOR_STATUS_NOTHING;
	sector.type = SECTOR_TYPE_SECTOR;
	sector.floor = 0;
	sector.height = 10;
	list_item = ft_lstnew(&sector, sizeof(t_sector));
	if (w->sector == NULL)
		w->sector = list_item;
	else
		ft_lstadd(&(w->sector), list_item);
}

/*
** **************************************************************************
**	void ft_delete_sector(t_wolf3d *w)
**
**	Function that delete sector.
** **************************************************************************
*/

void		ft_delete_sector(t_wolf3d *w)
{
	t_list		*list;
	t_sector	*s;
	int			i;

	if (w->sector == NULL)
		return ;
	list = w->sector;
	w->sector = w->sector->next;
	s = list->content;
	i = 0;
	while (i < s->vertex_count)
	{
		free(s->vertex[i]);
		i++;
	}
	free(s->vertex);
	if (s->neighbors != NULL)
		free(s->neighbors);
	free(list->content);
	free(list);
	w->sector_count--;
}

/*
** **************************************************************************
**	t_sector *ft_editor_search_sector_by_id(t_wolf3d *w, t_list *list, int i)
**
**	Function that search sector by id.
** **************************************************************************
*/

t_sector	*ft_editor_search_sector_by_id(t_wolf3d *w, t_list *list, int i)
{
	t_sector	*sector;

	(void)w;
	while (list)
	{
		sector = list->content;
		if (sector->id == i)
			return ((t_sector*)(list->content));
		list = list->next;
	}
	return (NULL);
}

/*
** **************************************************************************
**	void ft_map_set_new_sector(t_wolf3d *w, t_sector *s)
**
**
** **************************************************************************
*/

void		ft_map_set_new_sector(t_wolf3d *w, t_sector *s)
{
	ft_set_new_vertex_for_sector_list(w, s->vertex, s->vertex_count);
	ft_sectors_set_all_neighbors(w);
}
