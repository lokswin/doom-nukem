/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_motion_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:20:12 by drafe             #+#    #+#             */
/*   Updated: 2020/02/24 13:34:02 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_game_motion_move_pl(float dx, float dy, t_new_player *pl)
**	Function to check next sector in the way of the player
** **************************************************************************
*/

static int	ft_game_sc(t_vector3 *delt, \
				t_new_player *pl, int sec_nb)
{
	t_vector3		*vert;
	float			point_side;
	int				inter;
	int				i;

	if ((i = -1) && sec_nb < 0)
		return (-777);
	if (pl->m_over++ > pl->sectors_nb)
		return (-777);
	vert = pl->sectors[sec_nb].vertex;
	while ((++i < pl->sectors[sec_nb].npoints))
	{
		inter = ft_math_intersectbox(pl->pos, (t_vector3){pl->pos.x + \
		delt->x, pl->pos.y + delt->y, 0, 0}, vert[i], vert[i + 1]);
		point_side = ft_math_pointside((t_vector3){pl->pos.x + delt->x, \
			pl->pos.y + delt->y, 0, 0}, vert[i], vert[i + 1]);
		if (pl->sectors[sec_nb].neighbors[i] >= 0 && \
		pl->sectors[sec_nb].floor - pl->pos.z > -4)
			return (-666);
		if (pl->sectors[sec_nb].neighbors[i] < 0 && inter && point_side < 0)
			return (-666);
		if (inter && point_side < 0)
			return (ft_game_sc(delt, pl, pl->sectors[sec_nb].neighbors[i]));
	}
	return (sec_nb);
}

/*
** **************************************************************************
**	void ft_game_motion_move_pl(float dx, float dy, t_new_player *pl)
**	Function to check neighbor sector in the way of the player
** **************************************************************************
*/

int			ft_game_motion_chk_sec(t_new_sector *sect, \
t_vector3 *delt, int i, t_new_player *pl)
{
	t_vector3		*vert;
	float			point_side;
	int				inter;

	vert = sect->vertex;
	pl->m_over = 0;
	inter = ft_math_intersectbox((t_vector3){pl->pos.x, pl->pos.y, 0, 0}, \
	(t_vector3){pl->pos.x + delt->x, pl->pos.y + delt->y, 0, 0}, vert[i], \
	vert[i + 1]);
	point_side = ft_math_pointside((t_vector3){pl->pos.x + delt->x, \
		pl->pos.y + delt->y, 0, 0}, vert[i], vert[i + 1]);
	if (sect->neighbors[i] < 0 && inter && point_side < 0)
		return (-666);
	if (inter && point_side < 0)
		return (ft_game_sc(delt, pl, sect->neighbors[i]));
	return (-777);
}
