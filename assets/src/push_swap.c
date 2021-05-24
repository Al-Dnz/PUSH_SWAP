/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:13:29 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/24 20:42:52 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	treat_min(t_list **li_b, t_list **li_a, t_list *li_min)
{
	int sens;

	sens = optimized_shift(*li_b, li_min);
	while ((int)(*li_b)->content != (int)li_min->content)
	{
		if (sens == 0)
			shift_down(li_b, 2);
		else
			shift_up(li_b, 2);
	}
	transfer_top(li_b, li_a, 2);
	shift_down(li_a, 1);
}

void	treat_max(t_list **li_b, t_list **li_a, t_list *li_max)
{
	int sens;

	sens = optimized_shift(*li_b, li_max);
	while ((int)(*li_b)->content != (int)li_max->content)
	{
		if ( sens == 0)
			shift_down(li_b, 2);
		else
			shift_up(li_b, 2);
	}
	transfer_top(li_b, li_a, 2);
}

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
	t_list *ch_min;
	t_list *ch_max;
	t_list *temp;

	temp = NULL;
	
	ch_min = NULL;
	ch_max = NULL;
	
	brut_sort(&li_a, &li_b, &ledger);
	process_3(&li_a, &li_b);
	
	int reminder;
	while (ledger)
	{
		lst_cpy(&temp, li_b, ledger->n);
		list_merge_sort(&temp);

		reminder = 0;
		while (temp != NULL)
		{
			ch_min = temp;
			ch_max = ft_lstlast(temp);
			//treat_max(&li_b, &li_a, ch_max);
			//ft_lstclear(&ch_max, ft_del);
			printf("****************************************\n(%d)\n", (int)ch_min->content);
			ft_lstpop(&temp);
			
		}
		while (reminder--)
			shift_up(&li_a, 1); 
		
		
		
		ledger = ledger->next;
	}
	
	
	ft_putstr_fd("********************************\n", 1);
	display_list(li_a);
	//display_list(li_b);
	ft_putstr_fd("********************************\n", 1);
	ft_lstshift(li_a);
	display_list(li_a);
	ft_lstshift(li_a);
	display_list(li_a);

	

	printf("OPERATION_COUNT => [%d]\n", g_accumulator);
	//visual_list(li_a);
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
				ft_lstshift(temp);
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