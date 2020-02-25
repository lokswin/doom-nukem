/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:44:00 by dorange-          #+#    #+#             */
/*   Updated: 2020/02/21 18:23:00 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_gui_events_keydown_set_sector(t_wolf3d *w, SDL_Event *e)
** **************************************************************************
*/

void	ft_gui_events_keydown_set_sector(t_wolf3d *w, SDL_Event *e)
{
	int	check;

	check = 1;
	if (e->key.keysym.scancode == SDL_SCANCODE_SPACE)
		ft_gui_mousebuttonup_win_setsector_btnsavemap(w, *e, w->gui.dom, 0);
	else if (e->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		ft_gui_mousebuttonup_win_setsector_btncancel(w, *e, w->gui.dom, 0);
	else
		check = 0;
	if (check)
		ft_gui_redraw(w);
}

/*
** **************************************************************************
**	void ft_gui_events_keydown_me(t_wolf3d *w, SDL_Event *e)
** **************************************************************************
*/

void	ft_gui_events_keydown_me(t_wolf3d *w, SDL_Event *e)
{
	int	check;

	check = 1;
	if (e->key.keysym.scancode == SDL_SCANCODE_S)
		ft_gui_mousebuttonup_win_menu_btnsector(w, *e, w->gui.dom, 0);
	else if (e->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		ft_gui_mousebuttonup_win_editor_menu_btnmenu(w, *e, w->gui.dom, 0);
	else
		check = 0;
	if (check)
		ft_gui_redraw(w);
}

/*
** **************************************************************************
**	void ft_gui_events_keydowm_map(t_wolf3d *w, SDL_Event *e)
** **************************************************************************
*/

void	ft_gui_events_keydowm_map(t_wolf3d *w, SDL_Event *e)
{
	int	check;

	check = 1;
	if (e->key.keysym.scancode == SDL_SCANCODE_UP)
		w->gui_map.v.y -= 2.0;
	else if (e->key.keysym.scancode == SDL_SCANCODE_DOWN)
		w->gui_map.v.y += 2.0;
	else if (e->key.keysym.scancode == SDL_SCANCODE_LEFT)
		w->gui_map.v.x -= 2.0;
	else if (e->key.keysym.scancode == SDL_SCANCODE_RIGHT)
		w->gui_map.v.x += 2.0;
	else
		check = 0;
	if (check)
		ft_gui_redraw(w);
}

/*
** **************************************************************************
**	void ft_gui_events_keydown(t_wolf3d *w, SDL_Event *e)
** **************************************************************************
*/

void	ft_gui_events_keydown(t_wolf3d *w, SDL_Event *e)
{
	if (e->type == SDL_KEYDOWN)
	{
		if (w->gui.mode == GUI_MD_MENU)
		{
			(e->key.keysym.scancode == SDL_SCANCODE_ESCAPE) ? \
				w->sdl->running = 0 : 0;
		}
		if (w->gui.mode == GUI_MD_ME)
			ft_gui_events_keydowm_map(w, e);
		if (w->gui.mode == GUI_MD_ME)
			ft_gui_events_keydown_me(w, e);
		else if (w->gui.mode == GUI_MD_ME_SET_SECTOR)
			ft_gui_events_keydown_set_sector(w, e);
		if (w->gui.focus_elem != NULL)
			ft_gui_focus_keydown(w, *e, w->gui.focus_elem);
	}
}

/*
** **************************************************************************
**	void ft_gui_events(t_wolf3d *w)
**
**	Function that handle user events.
** **************************************************************************
*/

void	ft_gui_events(t_wolf3d *w)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		e.type == SDL_QUIT ? w->sdl->running = 0 : 0;
		ft_gui_events_keydown(w, &e);
		ft_gui_events_mouse(w, &e);
	}
	if (w->gui.search_elem == GUI_EVENT_ON || \
		w->gui.search_elem == GUI_EVENT_SEARCH)
	{
		ft_gui_redraw(w);
		w->gui.search_elem = GUI_EVENT_OFF;
	}
}
