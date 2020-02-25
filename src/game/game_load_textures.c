/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:31 by drafe             #+#    #+#             */
/*   Updated: 2020/02/24 16:00:50 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_game_transform_venom(t_new_texture *venom)
{
	unsigned int	i;
	Uint32			hex;

	i = 1;
	while (i < venom->h * venom->w)
	{
		hex = ft_rgb_to_hex(venom->pixels[i].r, venom->pixels[i].g, \
		venom->pixels[i].b);
		if (hex >= 15800000)
		{
			venom->pixels[i].a = 0;
		}
		i++;
	}
}

/*
** **************************************************************************
**	t_new_texture *load_all_textures(t_new_player *pl)
**	Function to load textures
** **************************************************************************
*/

t_new_texture	*ft_game_load_textures(t_new_player *pl)
{
	t_new_texture	*t_arr;

	pl->textures_nb = 15;
	t_arr = (t_new_texture *)ft_my_malloc(sizeof(t_new_texture) \
												* pl->textures_nb);
	t_arr[0] = ft_game_texture_parse("Img_tga/carpet_beige2.tga");
	t_arr[1] = ft_game_texture_parse("Img_tga/asphalt_concrete.tga");
	t_arr[2] = ft_game_texture_parse("Img_tga/bricks_red.tga");
	t_arr[3] = ft_game_texture_parse("Img_tga/bricks_white.tga");
	t_arr[4] = ft_game_texture_parse("Img_tga/rock1.tga");
	t_arr[5] = ft_game_texture_parse("Img_tga/cosmos.tga");
	t_arr[6] = ft_game_texture_parse("Img_tga/carpet_beige2.tga");
	t_arr[7] = ft_game_texture_parse("Img_tga/fence.tga");
	t_arr[8] = ft_game_texture_parse("Img_tga/revolver0.tga");
	t_arr[9] = ft_game_texture_parse("Img_tga/revolver1.tga");
	t_arr[10] = ft_game_texture_parse("Img_tga/revolver2.tga");
	t_arr[11] = ft_game_texture_parse("Img_tga/bricks_white.tga");
	t_arr[12] = ft_game_texture_parse("Img_tga/venom_face.tga");
	t_arr[13] = ft_game_texture_parse("Img_tga/graffiti.tga");
	t_arr[14] = ft_game_texture_parse("Img_tga/basketball.tga");
	ft_game_transform_venom(&t_arr[12]);
	return (t_arr);
}
