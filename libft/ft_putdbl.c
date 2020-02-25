/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:06:29 by tjuana            #+#    #+#             */
/*   Updated: 2020/02/24 20:36:17 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbl(double n, int p)
{
	int		i;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putnbr((int)n);
	ft_putchar('.');
	n -= (int)n;
	i = 0;
	while (i < p)
	{
		ft_putnbr(ft_abs((int)(n *= 10)));
		n -= (int)n;
		i++;
	}
}
