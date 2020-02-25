/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:32:36 by dorange-          #+#    #+#             */
/*   Updated: 2020/02/24 19:31:03 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				ft_game_events_exit(t_new_player *pl)
{
	ft_gui_elem_set_status(\
		ft_gui_search_elem_by_name(((t_wolf3d*)pl->wolf3d)->gui.dom, \
		"win_game"), GUI_ELEM_HIDDEN);
	ft_gui_elem_set_status(\
		ft_gui_search_elem_by_name(((t_wolf3d*)pl->wolf3d)->gui.dom, \
		"win_menu"), GUI_ELEM_VISIBLE);
	((t_wolf3d*)pl->wolf3d)->gui.mode = GUI_MD_MENU;
	((t_wolf3d*)pl->wolf3d)->player_status = 0;
	SDL_ShowCursor(SDL_ENABLE);
	SDL_SetRelativeMouseMode(0);
	return (0);
}

void			ft_game_hidden_message(t_list *dom)
{
	ft_gui_elem_set_status(\
		ft_gui_search_elem_by_name(dom, \
		"win_game_doortext"), GUI_ELEM_HIDDEN);
	ft_gui_elem_set_status(\
		ft_gui_search_elem_by_name(dom, \
		"win_game_diedtext"), GUI_ELEM_HIDDEN);
	ft_gui_elem_set_status(\
		ft_gui_search_elem_by_name(dom, \
		"win_game_diedbg"), GUI_ELEM_HIDDEN);
}

/*
** **************************************************************************
**	int ft_game_sub_events(t_new_sub_ev *se, t_new_player *pl)
**	Second function to manage key input
** **************************************************************************
*/

int				ft_game_sub_events(t_new_sub_ev *se, t_new_player *pl)
{
	if (se->ev.key.keysym.sym == SDLK_ESCAPE)
		return (ft_game_events_exit(pl));
	ft_game_sub_events_player(se, pl);
	ft_game_sub_events_moving(se, pl);
	return (1);
}

void			ft_game_mouse_events_click(t_new_player *pl)
{
	t_list		*list;
	t_list		*dom;

	dom = ((t_wolf3d*)pl->wolf3d)->gui.dom;
	ft_sound_play(pl->sound_pistol, 1);
	pl->count_sprite = 10;
	if (pl->bullet_count > 0)
	{
		list = ft_gui_search_elem_by_name(dom, "win_game_hud_pistolcount");
		ft_gui_elem_change_text(list, ft_itoa(--pl->bullet_count));
	}
	else if (pl->armors_count > 0)
	{
		list = ft_gui_search_elem_by_name(dom, "win_game_hud_armorscount");
		ft_gui_elem_change_text(list, ft_itoa(--pl->armors_count));
	}
	else if (pl->live_count > 0)
	{
		pl->live_count -= 10;
		ft_sound_play(pl->sound_death, 5);
		list = ft_gui_search_elem_by_name(dom, "win_game_hud_livescount");
		ft_gui_elem_change_text(list, ft_itoa(pl->live_count));
	}
	if (pl->live_count <= 0)
		ft_game_set_dead(pl, dom);
}
