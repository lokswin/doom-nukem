/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:31 by drafe             #+#    #+#             */
/*   Updated: 2020/02/24 16:48:09 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_free(t_new_player *pl, char *map)
{
	char			*lvl;

	free(pl->sectors);
	pl->sectors = NULL;
	lvl = ft_strdup(map);
	ft_strdel(&map);
	ft_game_my_parse_map(pl, lvl);
	ft_strdel(&lvl);
	free(pl->doors);
	pl->doors = NULL;
	free(pl->buttons);
	pl->buttons = NULL;
}

/*
** **************************************************************************
**	void ft_game_end_game(t_new_player *pl)
**	Function to end game
** **************************************************************************
*/

void			ft_game_end_game(t_new_player *pl, char *map)
{
	*pl = *ft_game_end_game2(pl, map);
}

t_new_player	*ft_game_end_game2(t_new_player *pl, char *map)
{
	int				j;
	int				i;
	t_new_sector	*sector;

	j = -1;
	while (j++ < (pl->file.count_sectors2 - 1))
	{
		sector = &pl->sectors[j];
		i = -1;
		while (i++ <= sector->npoints)
		{
			free(sector->vertex);
			sector->vertex = NULL;
			free(sector->neighbors);
			sector->neighbors = NULL;
		}
	}
	ft_strdel(&pl->lvl);
	ft_free(pl, map);
	return (pl);
}

/*
** **************************************************************************
**	t_new_player *load_next(t_new_player *pl, char *map)
**	Function to open next map
** **************************************************************************
*/

t_new_player	*load_next(t_new_player *pl, char *map)
{
	int				j;
	int				i;
	t_new_sector	*sector;

	if (!ft_strcmp(map, "EXIT"))
	{
		ft_game_set_exit(pl, ((t_wolf3d*)pl->wolf3d)->gui.dom);
		return (pl);
	}
	j = -1;
	while (j++ < (pl->file.count_sectors2 - 1))
	{
		sector = &pl->sectors[j];
		i = -1;
		while (i++ < sector->npoints)
		{
			free(sector->vertex);
			sector->vertex = NULL;
			free(sector->neighbors);
			sector->neighbors = NULL;
		}
	}
	ft_strdel(&pl->file.ag);
	ft_free(pl, map);
	return (pl);
}
