/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:21:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/09 14:40:45 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_list(t_list *li)
{
	while (li != NULL)
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd((int)li->content, 1);
		ft_putstr_fd("]->", 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

void	visual_list(t_list *li)
{
	int	n;

	while (li != NULL)
	{
		n = (int)li->content;
		while (n--)
			ft_putchar_fd('_', 1);
		ft_putchar_fd('\n', 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}
