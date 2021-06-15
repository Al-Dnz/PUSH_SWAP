/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:38:37 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 11:53:42 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*pre_last(t_list *li)
{
	if (li == NULL)
		return (NULL);
	while (li && li->next && li->next->next)
		li = li->next;
	return (li);
}

t_list	*pre_pre_last(t_list *li)
{
	if (li == NULL)
		return (NULL);
	while (li && li->next && li->next->next && li->next->next->next)
		li = li->next;
	return (li);
}

void	sort_3_head(t_list **li, int verbose, t_state *state)
{
	int a;
	int b;
	int c;

	a = (int)(*li)->content;
	b = (int)(*li)->next->content;
	c = (int)(*li)->next->next->content;
	if (a > b && b < c && c > a)
			swap_list(*li, verbose, state);
	if (b > a && b > c)
	{
		shift_down(li, verbose, state);
		swap_list(*li, verbose, state);
		shift_up(li, verbose, state);
		if (a > c)
			swap_list(*li, verbose, state);
		return;
	}
	if (a > b && a > c)
	{
		swap_list(*li, verbose, state);
		shift_down(li, verbose, state);
		swap_list(*li, verbose, state);
		shift_up(li, verbose, state);
		if (b > c)
			swap_list(*li, verbose, state);
	}
}

int is_3_last_order(t_list *li_b, t_list *last, t_list *prelast, t_list *preprelast, int sens)
{
	int 		n;
	static int	arr[3] = {0, 0, 0};

	n = 0;
	if (li_b ==  NULL || last == NULL || prelast == NULL || preprelast == NULL)
		return (0);
	while (li_b)
	{
		if((int)li_b->content == (int)preprelast->content)
			arr[0] = ++n;
		if((int)li_b->content == (int)prelast->content)
			arr[1] = ++n ;
		if((int)li_b->content == (int)last->content)
			arr[2] = ++n ;
		li_b = li_b->next;
	}
	if (n != 3)
		return (0);
	if (sens == 0 && arr[2] == 3 && arr[1] == 2 && arr[0] == 1)
		return (1);
	if (sens == 1 && arr[2] == 1 && arr[1] == 2 && arr[0] == 3)
		return (1);
	return (0);
}

typedef struct s_tb_2
{
	int		reminder;
	int		remind_swap;
	int		preprelast_and_prelast;
	//int		last_and_prelast;
	int		sens;
	t_list	*ch_min;
	t_list	*ch_max;
	t_list	*temp;
	t_list	*prelast;
	t_list	*preprelast;

}				t_tb_2;

void	set_toolbox(t_tb_2 *toolbox)
{
	toolbox->temp = NULL;
	toolbox->ch_min = NULL;
	toolbox->ch_max = NULL;
	toolbox->prelast = NULL;
	toolbox->preprelast = NULL;
}

void	last_part(t_state *state, t_reg *ledger)
{
	t_tb_2	toolbox;

	set_toolbox(&toolbox);
	while (ledger)
	{
		lst_cpy(&toolbox.temp, state->li_b, ledger->n);
		list_merge_sort(&toolbox.temp);
		toolbox.reminder = 0;
		toolbox.sens = 0;
		while (toolbox.temp)
		{
			toolbox.ch_min = toolbox.temp;
			toolbox.preprelast = pre_pre_last(toolbox.temp);
			toolbox.prelast = pre_last(toolbox.temp);
			toolbox.ch_max = ft_lstlast(toolbox.temp);
			toolbox.sens = optimized_shift(state->li_b, toolbox.ch_max);
			toolbox.remind_swap = 0;
			toolbox.preprelast_and_prelast = is_3_last_order(state->li_b, toolbox.ch_max, toolbox.prelast, toolbox.preprelast, toolbox.sens);
			while ((int)(state->li_b)->content != (int)toolbox.ch_max->content && toolbox.temp)
			{
				if ((int)(state->li_b)->content == (int)toolbox.ch_min->content)
				{
					toolbox.reminder++;
					transfer_top(&state->li_b, &state->li_a, 2, state);
					shift_down(&state->li_a, 1, state);
					toolbox.temp = toolbox.temp->next;
				}
				else if ((int)(state->li_b)->content == (int)toolbox.prelast->content)
				{
					if (toolbox.remind_swap == 0)
						toolbox.remind_swap = 1;
					transfer_top(&state->li_b, &state->li_a, 2, state);
				}
				else if ((int)(state->li_b)->content == (int)toolbox.preprelast->content && toolbox.preprelast_and_prelast)
				{
					toolbox.remind_swap = 2;
					transfer_top(&state->li_b, &state->li_a, 2, state);
				}
				else 
				{
					if (toolbox.sens == 0)
						shift_down(&state->li_b, 2, state);
					else if (toolbox.sens == 1)
						shift_up(&state->li_b, 2, state);
				}
			}
			transfer_top(&state->li_b, &state->li_a, 2, state);
			if (toolbox.remind_swap > 0)
			{
				sort_3_head(&state->li_a, 1, state);
				ft_lstshift(&toolbox.temp);
			}
			if (toolbox.remind_swap == 2)
				ft_lstshift(&toolbox.temp);
			ft_lstshift(&toolbox.temp);
		}
		while (toolbox.reminder--)
			shift_up(&state->li_a, 1, state);
		ft_lstclear(&toolbox.temp, &ft_del);
		ledger = ledger->next;
	}
	
}



void	process_100(t_state *state)
{
	t_reg	*ledger;
	
	ledger = NULL;
	brut_sort(&state->li_a, &state->li_b, &ledger, state);
	process_3(state);
	/*
	first_parts(state, ledger);
	
	while(ledger && ledger->next != NULL)
		ledger = ledger->next;
	*/
	last_part(state, ledger);
	
	register_clear(&ledger);
}


		/*
			if ((int)preprelast->content != (int)ch_min->content && ft_lstsize(temp) > 3 && (int)preprelast->content != (int)prelast->content)
				
			else
				preprelast_and_prelast = 0;
				
			if ((int)prelast->content != (int)ch_min->content && (int)prelast->content != (int)ch_max->content)
				last_and_prelast = 1;
			else
				last_and_prelast = 0;
			*/	