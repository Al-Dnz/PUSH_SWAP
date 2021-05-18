#include "header.h"

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

void	brut_sort(t_list **li_a, t_list **li_b, t_register **ledger)
{
	t_list	*pivot;

	int		size;
	int		size2;
	int		n;

	
	size2 = ft_lstsize(*li_a);
	while (size2 > 3)
	{
		pivot = find_median(*li_a);
		size = ft_lstsize(*li_a);
		n = 0;
		while (size--)
		{
			if ((int)(*li_a)->content < (int)pivot->content)
			{
				transfer_top(li_a, li_b, 1);
				//adjust_list_b(li_a, li_b);
				n++;
			}
			shift_up(li_a, 1);
		}
		printf("N = %d\n", n);
		register_add_front(ledger, register_new(n));
		size2 = ft_lstsize(*li_a);
	}
}

void	drain_by_max(t_list **li_b, t_list **li_a)
{
	t_list *tmp;
	while(*li_b)
	{
		tmp = list_max(*li_b);
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if ((*li_b)->next == tmp)
		{
			swap_list(*li_b, 2);
			transfer_top(li_b, li_a, 2);
		}	
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}

void process_chunk_head(t_list **li_1, t_list **li_2, int size, int sens)
{
	// li_a
	if (sens == 0)
	{
		if (size == 2 && (int)(*li_1)->content > (int)(*li_1)->next->content)
			swap_list(*li_1, 1);
		if (size ==  3)
			sort_3_head(li_1, 1);
	}
	// li_b
	else
	{
		if (size == 2)
	}
	
}

void	process_chunk(t_list **li_1, t_list **li_2, int size, int sens)
{
	int		reminder;
	int		verbose;
	int		new_size;
	int		median;

	verbose = 1 + sens;
	if (size < 4)
	{

			return;
	}
	
	

	reminder = 0;
	new_size  = 0;
	median = (int)find_chunk_median(*li_1, size)->content;
	while (size--)
	{
		if ((int)(*li_1)->content >= median)
		{
			new_size++;
			transfer_top(li_1, li_2, verbose);	
		}
		else
		{ 
			reminder++;
			shift_down(li_1, verbose);
		}
	}
	
	sens = 1 - sens;
	while (reminder--)
		shift_up(li_1, sens);
	process_chunk(li_2, li_1, new_size, sens);
	
}

void	sort_3_head(t_list **li, int verbose)
{
	int a;
	int b;
	int c;

	a = (int)(*li)->content;
	b = (int)(*li)->next->content;
	c = (int)(*li)->next->next->content;
	if (a > b && b < c && c > a)
			swap_list(*li, verbose);
	if (b > a && b > c)
	{
		shift_down(li, verbose);
		swap_list(*li, verbose);
		shift_up(li, verbose);
		
		if (a > c)
			swap_list(*li, verbose);
		
		return;
	}
	if (a > b && a > c)
	{
		swap_list(*li, verbose);
		shift_down(li, verbose);
		swap_list(*li, verbose);
		shift_up(li, verbose);
		if (b > c)
			swap_list(*li, verbose);
	}
}

void	rev_sort_3_head(t_list **li, int verbose)
{
	int a;
	int b;
	int c;

	a = (int)(*li)->content;
	b = (int)(*li)->next->content;
	c = (int)(*li)->next->next->content;
	if (a < b && a < c)
	{
		swap_list(*li, verbose);
		shift_down(li, verbose);
		swap_list(*li, verbose);
		shift_up(li, verbose);
		if (b < c)
			swap_list(*li, verbose);
	}
	if (b < a && b < c)
	{
		shift_down(li, verbose);
		swap_list(*li, verbose);
		shift_up(li, verbose);
		if (a < c)
			swap_list(*li, verbose);
	}
	if (a < b && b > c && c < 1)
		swap_list(*li, verbose);
}

void	process_100(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_register *ledger;

	ledger = NULL;
	brut_sort(li_a, li_b, &ledger);
	process_3(li_a, li_b);
	//drain_by_max(li_b, li_a);
	ft_putstr_fd("--------\n LEDGER\n", 1);
	display_register(ledger);
	ft_putstr_fd("--------\n", 1);
	ft_putstr_fd("chunk_median --> ", 1);
	//display_list(find_chunk_median(*li_b, 5));
	ft_putnbr_fd((int)find_chunk_median(*li_b, 7)->content, 1);
	ft_putstr_fd("\n*******\n", 1);
	
	while(li_b && ledger)
	{
	
			//display_register(ledger);
			if (ledger->n == 2)
			{
				if ((*li_b)->content < (*li_b)->next->content)
					swap_list(*li_b, 2);
				transfer_top(li_b, li_a, 2);
				transfer_top(li_b, li_a, 2);
				register_pop(&ledger);
			}
			process_chunk(li_b, li_a, (int)ledger->n, 1);
			//else
			//	drain_by_max(li_b, li_a);
			register_pop(&ledger);
			ft_putstr_fd("\n*******\n", 1);
			display_register(ledger);
			ft_putstr_fd("\n*******\n", 1);
			//process_chunk(li_b, li_a, (int)ledger->n, 1);

	}
	
	
	//register_clear(&ledger);	
}


//lst_is_sort(*li_a) < 1)// || 