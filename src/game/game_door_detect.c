/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_door_detect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:46:09 by drafe             #+#    #+#             */
/*   Updated: 2020/02/21 14:29:25 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	static int ft_game_door_bool(int dist, float degree)
**	Function to check angle between view vec and door center
** **************************************************************************
*/

static int	ft_game_door_bool(int dist, float degree)
{
	degree = (int)degree % 360;
	if ((degree >= 0) && (degree < 125) && (dist == 0))
		return (dist);
	else if ((degree >= 0) && (degree < 67) && (dist == 1))
		return (dist);
	else if ((degree >= 0) && (degree < 50) && (dist == 2))
		return (dist);
	else if ((degree >= 0) && (degree < 38) && (dist == 3))
		return (dist);
	else if ((degree >= 0) && (degree < 31) && (dist == 4))
		return (dist);
	return (-1);
}

/*
** **************************************************************************
**	static void door_v_find(t_new_player *pl)
**	Function to chooze nearest door vertexes
** **************************************************************************
*/

static int	ft_game_door_vert_find(t_new_player *pl, t_vector3 *vec, int s_nb)
{
	int	dist;
	int	tmp_dist;
	int	i;
	int	j;

	i = -1;
	j = -1;
	dist = 6;
	tmp_dist = 0;
	while (++i < pl->sectors[s_nb].npoints)
	{
		j = -1;
		while (++j < pl->sectors[s_nb].npoints)
		{
			vec->x = (pl->sectors[s_nb].vertex[i].x + \
			pl->sectors[s_nb].vertex[j].x) / 2;
			vec->y = (pl->sectors[s_nb].vertex[i].y + \
			pl->sectors[s_nb].vertex[j].y) / 2;
			vec->x = vec->x - pl->pos.x;
			vec->y = vec->y - pl->pos.y;
			tmp_dist = (int)sqrt(pow(vec->x, 2) + pow(vec->y, 2));
			tmp_dist <= dist ? dist = tmp_dist : 0;
		}
	}
	return (dist);
}

/*
** **************************************************************************
**	static int ft_game_door_dist(t_vector3 vec1, t_vector3 vec2)
**	Function to define distance to door
** **************************************************************************
*/

static int	ft_game_door_dist(t_new_player *pl, int s_nb)
{
	t_vector3	vec;
	t_vector3	vec2;
	int			tmp_dist;

	tmp_dist = 6;
	tmp_dist = ft_game_door_vert_find(pl, &vec, s_nb);
	vec2.x = pl->anglecos;
	vec2.y = pl->anglesin;
	vec = ft_vec3_normalize(vec);
	vec2 = ft_vec3_normalize(vec2);
	if (ft_game_door_bool(tmp_dist, \
			ft_math_to_deg(acos(ft_vec2_cos(vec, vec2)))) == -1)
		return (6);
	return (tmp_dist);
}

/*
** **************************************************************************
**	static int door_exist(t_new_player *pl)
**	Function to return door sector nb in front of player
** **************************************************************************
*/

int			ft_game_door_detect(t_new_player *pl)
{
	int	i;
	int	s_nb;
	int	dist;
	int	tmp_dist;
	int	door_sec_nb;

	i = -1;
	s_nb = -1;
	dist = 5;
	tmp_dist = 0;
	door_sec_nb = -1;
	while (++i < pl->sectors[pl->sector].npoints)
	{
		s_nb = pl->sectors[pl->sector].neighbors[i];
		if ((pl->sectors[pl->sector].neighbors[i] >= 0) && \
		(!pl->sectors[s_nb].floor && !pl->sectors[s_nb].ceil))
		{
			tmp_dist = ft_game_door_dist(pl, s_nb);
			if ((tmp_dist <= dist) && (door_sec_nb = s_nb))
				dist = tmp_dist;
		}
	}
	return (door_sec_nb);
}
