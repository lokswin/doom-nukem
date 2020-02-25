/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_gui_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:20:27 by dorange-          #+#    #+#             */
/*   Updated: 2020/02/24 19:00:42 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_game_gui_init_menu2(t_gui_elem *elem, t_list *head)
**	Function that init gui elements for hud.
** **************************************************************************
*/

static void	ft_gui_init_menu_2(t_gui_elem *elem, t_list *head)
{
	ft_gui_elem_init(&elem->child, "win_game_hud_pistolcount", \
		(t_gui_coord){250, 10, 0}, (t_gui_coord){354, 50, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_text(elem->child, "10", 16, "fonts/Raleway-Bold.ttf");
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_hud_armors", \
		(t_gui_coord){316, 16, 0}, \
		(t_gui_coord){348, 48, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_image(elem->child, "img/armors.png");
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_hud_armorscount", \
		(t_gui_coord){350, 10, 0}, (t_gui_coord){454, 50, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_text(elem->child, "10", 16, "fonts/Raleway-Bold.ttf");
	ft_gui_elem_set_parent(head, elem->child);
}

/*
** **************************************************************************
**	void ft_game_gui_init_menu(t_list *head)
**	Function that init gui elements for hud.
** **************************************************************************
*/

void		ft_game_gui_init_menu(t_list *head)
{
	t_gui_elem	*elem;

	elem = head->content;
	ft_gui_elem_init(&elem->child, "win_game_hud_live", \
		(t_gui_coord){118, 18, 0}, (t_gui_coord){144, 44, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_image(elem->child, "img/like.png");
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_hud_livescount", \
		(t_gui_coord){150, 10, 0}, (t_gui_coord){254, 50, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_text(elem->child, "100", 16, "fonts/Raleway-Bold.ttf");
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_hud_pistol", \
		(t_gui_coord){216, 16, 0}, \
		(t_gui_coord){248, 48, 0});
	ft_gui_elem_set_color(elem->child, 0xffffff);
	ft_gui_elem_set_image(elem->child, "img/pistol.png");
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_init_menu_2(elem, head);
}

/*
** **************************************************************************
**	void ft_game_gui_init_hud_died(t_list *head)
** **************************************************************************
*/

static void	ft_game_gui_init_hud_died(t_list *head, t_gui_elem *elem)
{
	ft_gui_elem_init(&elem->child, "win_game_diedbg", (t_gui_coord){0, 0, 0}, \
		(t_gui_coord){WIN_WIDTH, WIN_HEIGHT, 0});
	ft_gui_elem_set_color(elem->child, 0xbfff0000);
	ft_gui_elem_set_status(elem->child, GUI_ELEM_HIDDEN);
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_diedtext", \
		(t_gui_coord){450, 300, 0}, (t_gui_coord){WIN_WIDTH, WIN_HEIGHT, 0});
	ft_gui_elem_set_color(elem->child, 0xfff0000);
	ft_gui_elem_set_text(elem->child, "PRESS F", 72, \
		"fonts/Raleway-ExtraBold.ttf");
	ft_gui_elem_set_status(elem->child, GUI_ELEM_HIDDEN);
	ft_gui_elem_set_parent(head, elem->child);
}

/*
** **************************************************************************
**	void ft_game_gui_init_hud_exit(t_list *head)
** **************************************************************************
*/

static void	ft_game_gui_init_hud_exit(t_list *head, t_gui_elem *elem)
{
	ft_gui_elem_init(&elem->child, "win_game_exitbg", (t_gui_coord){0, 0, 0}, \
		(t_gui_coord){WIN_WIDTH, WIN_HEIGHT, 0});
	ft_gui_elem_set_color(elem->child, 0xbfcccccc);
	ft_gui_elem_set_status(elem->child, GUI_ELEM_HIDDEN);
	ft_gui_elem_set_parent(head, elem->child);
	ft_gui_elem_init(&elem->child, "win_game_exittext", \
		(t_gui_coord){380, 300, 0}, (t_gui_coord){WIN_WIDTH, WIN_HEIGHT, 0});
	ft_gui_elem_set_color(elem->child, 0xf000000);
	ft_gui_elem_set_text(elem->child, "GAME OVER", 72, \
		"fonts/Raleway-ExtraBold.ttf");
	ft_gui_elem_set_status(elem->child, GUI_ELEM_HIDDEN);
	ft_gui_elem_set_parent(head, elem->child);
}

/*
** **************************************************************************
**	void ft_game_gui_init_hud(t_list *head)
** **************************************************************************
*/

void		ft_game_gui_init_hud(t_list *head)
{
	t_gui_elem	*elem;

	elem = head->content;
	ft_gui_elem_init(&elem->child, "win_game_hud", \
		(t_gui_coord){100, 0, 0}, (t_gui_coord){WIN_WIDTH - 100, 60, 0});
	ft_gui_elem_set_color(elem->child, 0xbf000000);
	ft_gui_elem_set_parent(head, elem->child);
	ft_game_gui_init_menu(elem->child);
	ft_gui_elem_init(&elem->child, "win_game_doortext", \
		(t_gui_coord){300, 300, 0}, (t_gui_coord){WIN_WIDTH, WIN_HEIGHT, 0});
	ft_gui_elem_set_color(elem->child, 0xbfffff00);
	ft_gui_elem_set_text(elem->child, "DVER' MNE ZAPILI!", 72, \
		"fonts/Raleway-ExtraBold.ttf");
	ft_gui_elem_set_status(elem->child, GUI_ELEM_HIDDEN);
	ft_gui_elem_set_parent(head, elem->child);
	ft_game_gui_init_hud_died(head, elem);
	ft_game_gui_init_hud_exit(head, elem);
}
