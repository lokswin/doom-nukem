/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:04:05 by drafe             #+#    #+#             */
/*   Updated: 2020/02/24 19:24:54 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	static void ft_game_events_vel_2(t_new_player *pl, t_new_sub_ev *se,
**	\ t_new_others *ot)
**	Function manage player move
** **************************************************************************
*/

static void	ft_game_events_vel_2(t_new_player *pl, t_new_sub_ev *se, \
				t_new_others *ot)
{
	float	speed;
	int		push;

	if (se->wsad[3])
	{
		ot->move_vec[0] -= pl->anglesin * 0.33;
		ot->move_vec[1] += pl->anglecos * 0.33;
	}
	push = (se->wsad[0] || se->wsad[1] || se->wsad[2] || se->wsad[3]);
	speed = push ? 0.4 : 0.2;
	pl->velo.x = pl->velo.x * (1 - speed) + ot->move_vec[0] * speed;
	pl->velo.y = pl->velo.y * (1 - speed) + ot->move_vec[1] * speed;
	push == 1 ? ot->moving = 1 : ot->moving;
}

/*
** **************************************************************************
**	void ft_game_events_vel_dir(t_new_player *pl, t_new_sub_ev *se,
**		t_new_others *ot)
**	Function manage player velocity
** **************************************************************************
*/

void		ft_game_events_vel(t_new_player *pl, t_new_sub_ev *se, \
				t_new_others *ot)
{
	float	speed;

	speed = 0.33;
	ot->move_vec[0] = 0;
	ot->move_vec[1] = 0;
	if (se->wsad[0])
	{
		ot->move_vec[0] += pl->anglecos * (speed + speed * se->wsad[6]);
		ot->move_vec[1] += pl->anglesin * (speed + speed * se->wsad[6]);
	}
	if (se->wsad[1])
	{
		ot->move_vec[0] -= pl->anglecos * speed;
		ot->move_vec[1] -= pl->anglesin * speed;
	}
	if (se->wsad[2])
	{
		ot->move_vec[0] += pl->anglesin * speed;
		ot->move_vec[1] -= pl->anglecos * speed;
	}
	ft_game_events_vel_2(pl, se, ot);
}

/*
** **************************************************************************
**	void jumps(t_subevents *se, t_new_player *pl,
**	t_new_sector_ops *op, t_new_others *ot)
**	Function manage jumps
** **************************************************************************
*/

void		ft_game_events_jumps(t_new_sub_ev *se, t_new_player *pl, \
				t_new_others *ot)
{
	float	z;

	if (se->falling == 0)
		return ;
	if (pl->lunar == 1)
		pl->velo.z -= 0.015f;
	else
		pl->velo.z -= 0.1f;
	if (pl->fly == 1 && pl->velo.z <= 0)
		se->falling = 0;
	z = pl->pos.z + pl->velo.z;
	if (pl->velo.z < 0 && z < pl->sectors[pl->sector].floor + pl->hole.z)
	{
		pl->pos.z = pl->sectors[pl->sector].floor + pl->hole.z;
		pl->velo.z = 0;
		se->ground = 1;
	}
	else if (pl->velo.z > 0 && z > pl->sectors[pl->sector].ceil)
		pl->velo.z = 0;
	if (se->falling)
	{
		pl->pos.z += pl->velo.z;
		ot->moving = 1;
	}
}

/*
** **************************************************************************
**	void mouse_movement(t_new_mouse *ms, t_new_player *pl)
**	Function manage mouse
** **************************************************************************
*/

void		ft_game_events_new_mouse_move(t_new_mouse *ms, t_new_player *pl)
{
	SDL_GetRelativeMouseState(&ms->x, &ms->y);
	SDL_SetRelativeMouseMode(1);
	pl->angle += ms->x * 0.03f;
	ms->yaw = ft_math_clamp(ms->yaw + ms->y * 0.05f, -5, 5);
	pl->yaw = ms->yaw - pl->velo.z * 0.5f;
	pl->anglesin = sinf(pl->angle);
	pl->anglecos = cosf(pl->angle);
}
