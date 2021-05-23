#include "header.h"

void	sort_rest_chunk(t_list **li_1, t_list **li_2)
{
	t_list *tmp;
	int		n;
	int		n_bis;
	t_list *min;

	n = 0;
	if (*li_1 == NULL)
		return ;
	tmp = *li_1;
	while (tmp && tmp->next && lst_is_sort(tmp) < 1)
	{
		n++;
		tmp = tmp->next;
	}
	if (n == 0)
		return;
	if (n == 2 && (int)(*li_1)->content > (int)(*li_1)->next->content)
	{
		swap_list(*li_1, 1);
		return ;
	}
	if (n == 3)
	{
		sort_3_head(li_1, 1);
		return ;
	}
	n++;
	printf("{n = %d}\n", n);
	tmp = *li_1;
	n_bis = n;
	while (n--)
	{
		min = list_min(*li_1);
		while (*li_1 != min)
		{
			if (optimized_shift(*li_1, min))
				shift_up(li_1, 1);
			else
				shift_down(li_1, 1);
		}
		transfer_top(li_1, li_2, 1);
	}
	while (n_bis--)
		transfer_top(li_2, li_1, 2);
}

void	reduce_by_med(t_list **li_1, t_list **li_2, int sens, int size, t_register **temp)

void	process_chunk(t_list **li_1, t_list **li_2, int size, int sens)
{
	
	int		reminder;
	int		verbose;
	int		new_size;
	int		median;
	int		SIZE = size;

	//sens : [li_a : 0] , [li_b : 1]
	verbose = 1 + sens;

	if (size < 4)
	{
		process_chunk_head(li_1, li_2, SIZE, sens);
		return;
	}
	SIZE = 0;
	reminder = 0;
	new_size  = 0;
	median = (int)find_chunk_median(*li_1, size)->content;
	while (size--)
	{
		if (sens == 0)
		{
			display_list(*li_1);
			display_list(*li_2);
		}
		else 
		{
			display_list(*li_2);
			display_list(*li_1);
		}
		
		if (sens == 1 && (int)(*li_1)->content >= median)
		{
			new_size++;
			transfer_top(li_1, li_2, verbose);	
		}
		else if (sens == 0 && (int)(*li_1)->content < median)
		{
			new_size++;
			transfer_top(li_1, li_2, verbose);	
		}
		else
		{
			SIZE++;
			reminder++;
			shift_down(li_1, verbose);
		}
	}
	
	while (reminder--)
		shift_up(li_1, verbose);
	if (sens == 0)
		sort_rest_chunk(li_1, li_2);
	//process_chunk_head(li_1, li_2, SIZE, sens);
	
	sens = 1 - sens;
	if (new_size > 0)
		process_chunk(li_2, li_1, new_size, sens);
	
}

void	reduce_by_med(t_list **li_1, t_list **li_2, int sens, int size, t_register **temp)
{
	printf("{%d}\n",size);
	int	new_size;
	int median;
	int reminder;
	t_register *new;
	int size_2;

	reminder = 0;
	
	new_size = 0;
	if (size > ft_lstsize(*li_1))
		size = ft_lstsize(*li_1);
	
	if (size < 3)
	{
		process_chunk_head(li_1, li_2, size, sens);
		return ;
	}
	median = (int)find_chunk_median(*li_1, size)->content;
	while (size--)
	{
		if (sens == 0 && (int)(*li_1)->content <= median)
		{
			new_size++;
			transfer_top(li_1, li_2, 1);	
		}
		if (sens == 1 && (int)(*li_1)->content >= median)
		{
			new_size++;
			transfer_top(li_1, li_2, 1);	
		}
		else
		{
			reminder++;
			shift_down(li_1, sens + 1);
		}
	}
	if (sens == 0)
	{
		new = register_new(new_size);
		register_add_front(temp, new);	
	}
	size_2 = reminder;
	while (reminder--)
		shift_up(li_1, sens + 1);
	reduce_by_med(li_1, li_2, sens, size_2, temp);
}



void process_chunk_head(t_list **li_1, t_list **li_2, int size, int sens)
{
	// li_a
	if (size == 0)
		return ;
	if (size < 4)
	{
		if (sens == 0)
		{
			if (size == 2 && (int)(*li_1)->content > (int)(*li_1)->next->content)
				swap_list(*li_1, sens + 1);
			if (size ==  3)
				sort_3_head(li_1, sens + 1);
		}
		// li_b
		else
		{
			if (size == 2 && (int)(*li_1)->content < (int)(*li_1)->next->content)
				swap_list(*li_1, sens + 1);
			if (size ==  3)
				rev_sort_3_head(li_1, sens + 1);
			while (size--)
				transfer_top(li_1, li_2, sens + 1);
		}
	}
}

/*

	display_register(ledger);	
	display_list(li_a);
	display_list(li_b);
	
	printf("--------------------------\n");
	reduce_by_med(&li_b, &li_a, 1, ledger->n, NULL);
	display_register(ledger);
	display_list(li_a);
	display_list(li_b);
	register_pop(&ledger);

	printf("--------------------------\n");
	reduce_by_med(&li_b, &li_a, 1, ledger->n, NULL);
	display_register(ledger);
	display_list(li_a);
	display_list(li_b);
	register_pop(&ledger);
	
	printf("--------------------------\n");
	
	reduce_by_med(&li_b, &li_a, 1, ledger->n, NULL);
	
	while (lst_is_sort(li_a) < 1)
	{
		reduce_by_med(&li_a, &li_b, 0, count_sort(li_a) + 1, &new_ledger);
		while (new_ledger)
		{
			reduce_by_med(&li_b, &li_a, 1, new_ledger->n, NULL);
			if (new_ledger->n < 4)
				process_chunk_head(&li_a, &li_b, new_ledger->n, 0);

			register_pop(&new_ledger);
		}
	}
	
	display_register(ledger);
	display_list(li_a);
	display_list(li_b);
	register_pop(&ledger);

	printf("--------------------------\n");

	*/



void	process_100(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_register *ledger;

	ledger = NULL;
	
	brut_sort(li_a, li_b, &ledger);
	process_3(li_a, li_b);
	//drain_by_max(li_b, li_a);
	ft_putstr_fd("--------\n", 1);
	ft_putstr_fd("chunk_median --> ", 1);
	//display_list(find_chunk_median(*li_b, 5));
	ft_putnbr_fd((int)find_chunk_median(*li_b, 7)->content, 1);
	ft_putstr_fd("\n*******\n", 1);
	
			int n = 4;
			ft_putstr_fd("\n LEDGER -> ", 1);
			display_register(ledger);
			printf("____init____\n");
				display_list(*li_a);
				display_list(*li_b);
				printf("__________\n");
			while (n--)
			{
				while (chunk_is_sort(*li_a, ledger->n))
					process_chunk(li_b, li_a, (int)ledger->n, 1);
				ft_putstr_fd("\n LEDGER -> ", 1);
				display_register(ledger);
				printf("__________\n");
				display_list(*li_a);
				display_list(*li_b);
				printf("__________\n");
				register_pop(&ledger);
			}
			
			/*
			while (n--)
			{	
				printf("{%d}**********\n", n);
				display_register(ledger);
				printf("**********\n");
				printf("__________\n");
				display_list(*li_a);
				display_list(*li_b);
				printf("__________\n");	
			}
			*/
			
	//}
	
	
	//register_clear(&ledger);	
}


