/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:42:01 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/10 18:19:01 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_state	state;
	int		error;

	state.li_a = NULL;
	state.li_b = NULL;
	state.seq = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	parser(&state.li_a, argc, argv, &error);
	if (error)
		return (quit(&state.li_a, &state.li_b, error, &state));

	//display_list(state.li_a);
	//display_list(state.li_b);
	//ft_putstr_fd("********************************\n", 1);
	
	switch_process(&state);
	read_seq(state.seq);
	
	//display_list(state.li_a);
	//display_list(state.li_b);
	
	return (quit(&state.li_a, &state.li_b, error, &state));
}












/*
t_reg *ledger;
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


ft_putstr_fd("----------------------------------\n", 1);
		
		//display_list(temp);
		while ((ledger->n)--)
			transfer_top(&li_b, &li_a, 0);
		//list_merge_sort(&li_b);
		ft_putstr_fd("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n", 1);
		display_list(li_b);
		ft_lstclear(&temp, ft_del);








printf("****************************\n(%d)\n",(int)ch_min->content);
			printf("min(%d)\n",(int)ch_min->content);
			printf("max(%d)\n",(int)ch_max->content);
			printf("dist(%d)\n",dist_to_lst(li_b, ch_min));
			ft_lstpop(&temp);
			
			if (1)//dist_to_lst(li_b, ch_min) < dist_to_lst(li_b, ch_max))
			{
				reminder++;
				treat_min(&li_b, &li_a, ch_min);
				ft_lstpop(&temp);
			}	
			else
			{
				treat_max(&li_b, &li_a, ch_max);
				ft_lstshift(&temp);
			}



	//if (dist_to_lst(li_b, ch_min) >= dist_to_lst(li_b, ch_max))
			if (1)
			{
				reminder++;
				treat_min(&li_b, &li_a, ch_min);
				ft_lstpop(&temp);
			}	
			else
			{
				treat_max(&li_b, &li_a, ch_max);
				ft_lstclear(&ch_max, ft_del);
			}		
*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------