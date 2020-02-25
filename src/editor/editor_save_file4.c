/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_save_file4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:46:49 by tjuana            #+#    #+#             */
/*   Updated: 2020/02/24 20:14:30 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_player_help(t_wolf3d *w, char *join, char *itoa)
{
	char	*tmp;

	tmp = ft_strdup(join);
	ft_strdel(&join);
	join = ft_strjoin(tmp, itoa);
	ft_strdel(&itoa);
	ft_strdel(&tmp);
	ft_putstr_fd(join, w->file.fd);
	ft_strdel(&join);
}
