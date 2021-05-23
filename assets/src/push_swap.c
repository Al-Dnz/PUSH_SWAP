/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:13:29 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/21 22:56:34 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*li_a;
	t_list	*li_b;
	//t_state	state;
	int		error;

	li_a = NULL;
	li_b = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	/*
	flag_parser(&state, argc, argv);
	printf("-v => %d\n-c => %d\n", state.verbose, state.color);
	*/
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	parser(&li_a, argc, argv, &error);
	display_list(li_a);
	display_list(li_b);
	if (error)
		return (quit(&li_a, &li_b, error));
	ft_putstr_fd("median= ", 1);
	ft_putnbr_fd((int)find_median(li_a)->content, 1);
	int n = 3;
	printf("\npivot[%d] => %d\n", n ,(int)pivot_list(li_a, n)->content);
	ft_putstr_fd("\n", 1);

	
	//process_100(&li_a, &li_b);
	//sort_rest_chunk(&li_a, &li_b);
	
	
	t_register *ledger;
	ledger = NULL;
	t_register *new_ledger;
	new_ledger = NULL;
	
	
	brut_sort(&li_a, &li_b, &ledger);
	process_3(&li_a, &li_b);

	int size;
	int ch_min;
	int ch_max;
	int reminder;
	while (ledger)
	{
		size = ledger->n;
		ch_min = chunk_min(li_b, size);
		ch_max = chunk_max(li_b, size);
		
		reminder = 0;
		if (dist_to_lst(li_b, ch_min) < dist_to_lst(li_b, ch_max))
		{
			while (li_b != ch_min)
			{
				reminder++;
				shift_down(&li_b, 2);
			}
			transfer_top(&li_b, &li_a, 2);
			shift_down(&li_a, 1);
		}
		else
		{
			while (li_b != ch_max)
			{
				reminder++;
				shift_down(&li_b, 2);
			}
			transfer_top(&li_b, &li_a, 2);
		}
		//drain_by_max(&li_b, &li_a, size);
		size--;
		ledger = ledger->next;
	}
	display_list(li_a);
	display_list(li_b);
	printf("OPERATION_COUNT => [%d]\n", g_accumulator);
	return (quit(&li_a, &li_b, error));
}


/*
t_register *ledger;
	ledger = NULL;
brut_sort(&li_a, &li_b, &ledger);
	display_register(ledger);
	process_chunk(&li_b, &li_a , ledger->n , 1);
	
	
	register_pop(&ledger);
	display_register(ledger);
	process_chunk(&li_b, &li_a , ledger->n , 1);
	
	*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
while (ledger)
	{
		reduce_by_med(&li_b, &li_a, 1, ledger->n, NULL);
		
		while (1)
		{
			reduce_by_med(&li_a, &li_b, 0, count_sort(li_a), &new_ledger);
			while (new_ledger)
			{
				while (new_ledger->n > 0)
				{
					//reduce_by_med(&li_b, &li_a, 1, new_ledger->n, NULL);
					transfer_top(&li_b, &li_a, 2);
					(new_ledger->n)--;
				}
				register_pop(&new_ledger);
			}
			
	
			if (lst_is_sort(li_a) == 1)
				break;
		}
		register_pop(&ledger);
	}
	*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------