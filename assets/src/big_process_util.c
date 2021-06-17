/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:59 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 17:49:08 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_med_of_med(t_list *li)
{
	t_list	*temp;
	t_list	*res_li;
	int		med;
	int		res;

	temp = NULL;
	res_li = find_median(li);
	med = (int)res_li->content;
	ft_lstclear(&res_li, &ft_del);
	while (li)
	{
		if ((int)li->content < med)
			ft_lstadd_back(&temp, ft_lstnew(li->content));
		li = li->next;
	}
	res_li = find_median(temp);
	res = (int)res_li->content;
	ft_lstclear(&temp, &ft_del);
	ft_lstclear(&res_li, &ft_del);
	return (res);
}

void	adjust_list_b(t_list **li_b, int med_of_med, int first, t_state *state)
{
	if ((int)(*li_b)->content <= med_of_med && first)
		shift_down(li_b, 2, state);
}

void	brut_sort(t_list **li_a, t_list **li_b, t_reg **ledger, t_state *state)
{
	t_tb_1	toolbox;

	toolbox.first = 1;
	toolbox.size2 = ft_lstsize(*li_a);
	while (toolbox.size2 > 3)
	{
		toolbox.pivot = find_median(*li_a);
		toolbox.size = ft_lstsize(*li_a);
		toolbox.n = 0;
		toolbox.med_of_med = find_med_of_med(*li_a);
		while (toolbox.size--)
		{
			if ((int)(*li_a)->content < (int)toolbox.pivot->content)
			{
				transfer_top(li_a, li_b, 1, state);
				adjust_list_b(li_b, toolbox.med_of_med, toolbox.first, state);
				toolbox.n++;
			}
			shift_up(li_a, 1, state);
		}
		toolbox.first = 0;
		register_add_front(ledger, register_new(toolbox.n));
		ft_lstclear(&(toolbox.pivot), ft_del);
		toolbox.size2 = ft_lstsize(*li_a);
	}
}
