/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_pushswap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:25:42 by alexdnz           #+#    #+#             */
/*   Updated: 2021/05/04 22:57:16 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	process_2(t_list **li_a, t_list **li_b)
{
	(void)li_b;
	if (lst_is_sort(*li_a) < 1)
	{
			g_accumulator++;
			ft_putstr_fd("sa\n", 1);
			swap_list(*li_a);
	}
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
	
	if (forbidden_seq(*li_a))
	{
			g_accumulator++;
			ft_putstr_fd("sa\n", 1);
			swap_list(*li_a);
	}
	sens = optimized_shift(*li_a, list_min(*li_a));
		while (lst_is_sort(*li_a) < 1)
		{
			g_accumulator++;
			if(sens == 0)
			{
					ft_putstr_fd("ra\n", 1);
					shift_down(li_a);
			}
			else
			{
					ft_putstr_fd("rra\n", 1);
					shift_up(li_a);
			}
			
		}
		
}

void	process_5(t_list **li_a, t_list **li_b)
{
	sort_by_push(li_a, li_b);
	process_3(li_a, li_b);
	bring_back(li_a, li_b);
}

void	process_60(t_list **li_a, t_list **li_b)
{
	(void)li_a;
	(void)li_b;
	divide_from_median(li_a, li_b);
	//process_3(li_a, li_b);
	//bring_back(li_a, li_b);
}


void	switch_push_swap(t_list **li_a, t_list **li_b)
{
	int size;
	
	size = ft_lstsize(*li_a);
	
	/*
	if (lst_is_sort(*li_a) == -1)
	{
		
		while (lst_is_sort(*li_a) < 1)
		{
			g_accumulator++;
			ft_putstr_fd("ra\n", 1);
			swap_list(*li_a);
			if (lst_is_sort(*li_a) == 1)
				break;
			shift_up(li_a);
		}
			printf("YOLOPOLO\n");
			return;
		}
	*/
	
	if (size == 1)
		return;
	if (size == 2)
	{
		process_2(li_a, li_b);
		return;
	}
		
	if (size == 3)
	{
		process_3(li_a, li_b);
		return;
	}
		
	if (size < 60)
	{
		process_5(li_a, li_b);
		return;
	}
	if (size <= 100)
	{
		process_60(li_a, li_b);
		return;
	}
	

}

/*
void	process_3(t_list **li_a, t_list **li_b)
{
	(void)li_b;

		if ((int)(*li_a)->content > (int)(*li_a)->next->content)
		{
			g_accumulator++;
			ft_putstr_fd("sa\n", 1);
			swap_list(*li_a);
		}
		if (lst_is_sort(*li_a) < 1)
		{
			g_accumulator++;
			ft_putstr_fd("ra\n", 1);
			shift_down(li_a);
		}
		if ((int)(*li_a)->content > (int)(*li_a)->next->content)
		{
			g_accumulator++;
			ft_putstr_fd("sa\n", 1);
			swap_list(*li_a);
		}
		if (lst_is_sort(*li_a) < 1)
		{
			g_accumulator++;
			ft_putstr_fd("ra\n", 1);
			shift_down(li_a);
		}
	
	
}
*/