/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:47:27 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/30 20:19:37 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swapper(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "sa") == 0)
		swap_list(*li_a);
	if (ft_strcmp(str, "sb") == 0)
		swap_list(*li_b);
	if (ft_strcmp(str, "ss") == 0)
	{
		swap_list(*li_a);
		swap_list(*li_b);
	}
}

void	pusher(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "pa") == 0)
		transfer_top(li_a, li_b);
	if (ft_strcmp(str, "pb") == 0)
		transfer_top(li_b, li_a);
}

void	rotater(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "ra") == 0)
		shift_up(li_a);
	if (ft_strcmp(str, "rb") == 0)
		shift_up(li_b);
	if (ft_strcmp(str, "rr") == 0)
	{
		shift_up(li_a);
		shift_up(li_b);
	}
	if (ft_strcmp(str, "rra") == 0)
		shift_down(li_a);
	if (ft_strcmp(str, "rrb") == 0)
		shift_down(li_b);
	if (ft_strcmp(str, "rrr") == 0)
	{
		shift_down(li_a);
		shift_down(li_b);
	}
}

void	switcher(char *str, t_list **li_a, t_list **li_b)
{	
	if (str[0] == 's')
		swapper(str, li_a, li_b);
	if (str[0] == 'p')
		pusher(str, li_a, li_b);
	if (str[0] == 'r')
		rotater(str, li_a, li_b);
	//display_list(*li_a);
	//display_list(*li_b);
}
