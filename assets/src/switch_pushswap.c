/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_pushswap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:25:42 by alexdnz           #+#    #+#             */
/*   Updated: 2021/05/15 15:28:57 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	process_2(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_2\n");
	(void)li_b;
	if (lst_is_sort(*li_a) < 1)
		swap_list(*li_a, 1);
}

int	forbidden_seq(t_list *li)
{
	t_list *temp;
	int	min;
	int max;
	int mid;

	min = (int)list_min(li)->content;
	max = (int)list_max(li)->content;
	temp = li;
	while (temp)
	{
		if ((int)(temp)->content != min && (int)(temp)->content != max)
			mid = (int)(temp)->content;
		temp = temp->next;
	}
	while (li && li->next)
	{
		if (((int)(li)->content == max && (int)(li)->next->content == mid) ||
				((int)(li)->content == mid && (int)(li)->next->content == min) ||
				((int)(li)->content == min && (int)(li)->next->content == max))
				return (1);
		li = li->next;
	}
	return (0);
}

void	process_3(t_list **li_a, t_list **li_b)
{
	(void)li_b;
	int	sens;
	
	printf("PROCESS_3\n");
	if (forbidden_seq(*li_a))
		swap_list(*li_a, 1);
	sens = optimized_shift(*li_a, list_min(*li_a));
	while (lst_is_sort(*li_a) < 1)
	{
		if(sens == 0)
			shift_down(li_a, 1);
		else
			shift_up(li_a, 1);
	}
}

void	process_5(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_5\n");
	sort_by_push(li_a, li_b);
	process_3(li_a, li_b);
	bring_back(li_a, li_b);
}

void	adjust_list_b(t_list **li_a, t_list **li_b)
{
	t_list	*li_min;
	t_list	*li_max;
	(void)li_a;

	li_min = list_min(*li_b);
	li_max = list_max(*li_b);

	if (ft_lstsize(*li_b) <= 2)
		return;
	if ((int)(*li_b)->content <= (int)li_min->content)
	{
		shift_down(li_b, 2);
		return;
	}
	/*
	if ((int)(*li_b)->content <= (int)(*li_b)->next->content && (int)(*li_b)->content > (int)li_min->content
	&& (int)(*li_a)->content < (int)(*li_a)->next->content)
	{
		double_swap_list(*li_a, *li_b, 1);
		return;
	}
	*/
	if ((int)(*li_b)->content <= (int)(*li_b)->next->content && (int)(*li_b)->content > (int)li_min->content)
	{
		swap_list(*li_b, 2);
		return;
	}
		
}

void	process_100(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_list *pivot;
	int		size;
	int		size2;

	size2 = ft_lstsize(*li_a);
	while (size2 > 3)
	{
		pivot = find_median(*li_a);
		size = ft_lstsize(*li_a);
		while (size--)
		{
			if ((int)(*li_a)->content < (int)pivot->content)
			{
				transfer_top(li_a, li_b, 1);
				
				//adjust_list_b(li_a, li_b);
			}
			shift_up(li_a, 1);
		}
		size2 = ft_lstsize(*li_a);
	}
	process_3(li_a, li_b);
	t_list *tmp;
	while(*li_b)
	{
		tmp = list_max(*li_b);
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if ((*li_b)->next == tmp)
		{
			swap_list(*li_b, 2);
			t ransfer_top(li_b, li_a, 2);
		}	
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}

/*
void	process_100(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_list *pivot;
	int		size;
	int		size2;

	size2 = ft_lstsize(*li_a);
	while (size2 > 3)
	{
		pivot = find_median(*li_a);
		size = ft_lstsize(*li_a);
		while (size--)
		{
			if ((int)(*li_a)->content < (int)pivot->content)
			{
				transfer_top(li_a, li_b, 1);
				
				//adjust_list_b(li_a, li_b);
			}
			shift_up(li_a, 1);
		}
		size2 = ft_lstsize(*li_a);
	}
	process_3(li_a, li_b);
	t_list *tmp;
	while(*li_b)
	{
		tmp = list_max(*li_b);
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}
*/
/*
void	process_100(t_list **li_a, t_list **li_b)
{
	(void)li_b;	
	printf("PROCESS_100\n");
	t_list *pivot;
	int		size;

	pivot = pivot_list(*li_a, 2);
	size = ft_lstsize(*li_a);
	while (*li_a)
	{
		g_accumulator++;
		transfer_top(li_a, li_b, 1);
	}
	t_list *tmp;
	while(*li_b)
	{
		tmp = list_max(*li_b);
		g_accumulator++;
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}
*/
