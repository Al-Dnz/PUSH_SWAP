/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:38:37 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/11 16:38:04 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	treat_min(t_list **li_b, t_list **li_a, t_list *li_min, t_state *state)
{
	int	sens;

	sens = optimized_shift(*li_b, li_min);
	while ((int)(*li_b)->content != (int)li_min->content)
	{
		if (sens == 0)
			shift_down(li_b, 2, state);
		else
			shift_up(li_b, 2, state);
	}
	transfer_top(li_b, li_a, 2, state);
	shift_down(li_a, 1, state);
}

void	treat_max(t_list **li_b, t_list **li_a, t_list *li_max, t_state *state)
{
	int	sens;

	sens = optimized_shift(*li_b, li_max);
	while ((int)(*li_b)->content != (int)li_max->content)
	{
		if (sens == 0)
			shift_down(li_b, 2, state);
		else
			shift_up(li_b, 2, state);
	}
	transfer_top(li_b, li_a, 2, state);
}

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


int is_3_last_order(t_list *li_b, t_list *chmax, t_list *prelast, t_list *preprelast)
{
	//int n;
	int arr[2];

	//n = 0;
	arr[0] = 0;
	arr[1] = 0;
	if (li_b ==  NULL || chmax == NULL || prelast == NULL || preprelast == NULL)
		return (0);
	while ((int)li_b->content != (int)chmax->content)
	{
		if((int)li_b->content == (int)preprelast->content)
			arr[0] = 1;
		if((int)li_b->content == (int)prelast->content)
			arr[1] = 1 ;
		li_b = li_b->next;
	}
	if (arr[0] == 1 && arr[1] == 1)
		return (1);
	return (0);
}

void	last_part(t_state *state, t_reg *ledger)
{
	int		reminder;
	int		remind_swap;
	int		remind_swap_bis;
	int		sens;
	t_list	*ch_min;
	t_list	*ch_max;
	t_list	*temp;
	t_list	*prelast;
	t_list	*preprelast;

	temp = NULL;
	ch_min = NULL;
	ch_max = NULL;
	prelast = NULL;
	preprelast = NULL;
	while (ledger)
	{
		lst_cpy(&temp, state->li_b, ledger->n);
		list_merge_sort(&temp);
		reminder = 0;
		sens = 0;
		while (temp)
		{
			remind_swap = 0;
			
			ch_min = temp;
			prelast = pre_last(temp);
			preprelast = pre_pre_last(temp);
			ch_max = ft_lstlast(temp);
			sens = optimized_shift(state->li_b, ch_max);
			remind_swap_bis = is_3_last_order(state->li_b, ch_max, prelast, preprelast);
			while ((int)(state->li_b)->content != (int)ch_max->content)
			{
				if ((int)(state->li_b)->content == (int)ch_min->content)
				{
					reminder++;
					transfer_top(&state->li_b, &state->li_a, 2, state);
					shift_down(&state->li_a, 1, state);
					temp = temp->next;
				}
				else if ((int)(state->li_b)->content == (int)preprelast->content && remind_swap_bis)
					transfer_top(&state->li_b, &state->li_a, 2, state);
				else if ((int)(state->li_b)->content == (int)prelast->content)
				{
					remind_swap = 1;
					transfer_top(&state->li_b, &state->li_a, 2, state);
				}
				else if (sens == 0)
					shift_down(&state->li_b, 2, state);
				else if (sens == 1)
					shift_up(&state->li_b, 2, state);
			}
			transfer_top(&state->li_b, &state->li_a, 2, state);
			if (remind_swap == 1 && remind_swap_bis != 1)
			{
				swap_list(state->li_a, 1, state);
				ft_lstshift(&temp);
			}
			else if (remind_swap_bis)
			{
				sort_3_head(&state->li_a, 1, state);
				ft_lstshift(&temp);
				ft_lstshift(&temp);
			}
			ft_lstshift(&temp);
		}
		while (reminder--)
			shift_up(&state->li_a, 1, state);
		//ft_lstclear(&temp, &ft_del);
		ledger = ledger->next;
	}
	
}

void	first_parts(t_state *state, t_reg *ledger)
{
	int		reminder;
	t_list	*ch_min;
	t_list	*ch_max;
	t_list	*temp;

	temp = NULL;
	ch_min = NULL;
	ch_max = NULL;
	while (ledger)
	{
		lst_cpy(&temp, state->li_b, ledger->n);
		list_merge_sort(&temp);
		reminder = 0;
		while (temp)
		{
			ch_min = temp;
			ch_max = ft_lstlast(temp);
			if (dist_to_lst(state->li_b, ch_min) < dist_to_lst(state->li_b, ch_max))
			{
				reminder++;
				treat_min(&state->li_b, &state->li_a, ch_min, state);
				ft_lstpop(&temp);
			}	
			else
			{
				treat_max(&state->li_b, &state->li_a, ch_max, state);
				ft_lstshift(&temp);
			}
		}
		while (reminder--)
			shift_up(&state->li_a, 1, state);
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
