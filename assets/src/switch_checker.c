/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:47:27 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/29 18:57:48 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swapper(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "sa") == 0)
		swap_list(*li_a, 0);
	if (ft_strcmp(str, "sb") == 0)
		swap_list(*li_b, 0);
	if (ft_strcmp(str, "ss") == 0)
	{
		swap_list(*li_a, 0);
		swap_list(*li_b, 0);
	}
}

void	pusher(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "pa") == 0)
		transfer_top(li_a, li_b, 0);
	if (ft_strcmp(str, "pb") == 0)
		transfer_top(li_b, li_a, 0);
}

void	rotater(char *str, t_list **li_a, t_list **li_b)
{
	if (ft_strcmp(str, "ra") == 0)
		shift_up(li_a, 0);
	if (ft_strcmp(str, "rb") == 0)
		shift_up(li_b, 0);
	if (ft_strcmp(str, "rr") == 0)
	{
		shift_up(li_a, 0);
		shift_up(li_b, 0);
	}
	if (ft_strcmp(str, "rra") == 0)
		shift_down(li_a, 0);
	if (ft_strcmp(str, "rrb") == 0)
		shift_down(li_b, 0);
	if (ft_strcmp(str, "rrr") == 0)
	{
		shift_down(li_a, 0);
		shift_down(li_b, 0);
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
}
