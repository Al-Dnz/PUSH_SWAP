/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_pushswap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:03:14 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 13:17:09 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_by_push(t_list **li_a, t_list **li_b, t_state *state)
{
	t_list	*list_inf;

	while (ft_lstsize(*li_a) > 3)
	{
		list_inf = list_min(*li_a);
		while (*li_a != list_inf)
		{
			if (optimized_shift(*li_a, list_inf))
				shift_up(li_a, 1, state);
			else
				shift_down(li_a, 1, state);
		}
		transfer_top(li_a, li_b, 1, state);
	}
}

void	switch_process(t_state *state)
{
	int	size;

	size = ft_lstsize((state->li_a));
	if (lst_is_sort((state->li_a)) == 1 || size == 1)
		return ;
	if (size == 2)
	{
		process_2(state);
		return ;
	}	
	if (size == 3)
	{
		process_3(state);
		return ;
	}
	if (size < 60)
	{
		process_5(state);
		return ;
	}
	if (size <= 1000)
	{
		process_100(state);
		return ;
	}	
}
