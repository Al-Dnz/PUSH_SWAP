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

void	reduce_by_med(t_list **li_1, t_list **li_2, int sens, int size, t_reg **temp);

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

void	reduce_by_med(t_list **li_1, t_list **li_2, int sens, int size, t_reg **temp)
{
	printf("{%d}\n",size);
	int	new_size;
	int median;
	int reminder;
	t_reg *new;
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



void	process_100_bis(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_reg *ledger;

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


void	drain_by_max(t_list **li_b, t_list **li_a, int size);
int		max_arr(int *arr, int size);
int		count_sort(t_list *li);
void	divide_from_median(t_list **li_a, t_list **li_b);

void	adjust_list_b(t_list **li_b, int first)
{
	static int initialised;
	static int	li_min;
	static int	li_max;

	if (initialised == 0)
	{
		li_min = (int)(*li_b)->content;
		li_max = (int)(*li_b)->content;
	}
	if ((int)(*li_b)->content > li_max)
		li_max = (int)(*li_b)->content;
	else if ((int)(*li_b)->content < li_min && first)
	{
		li_min = (int)(*li_b)->content;
		shift_down(li_b, 2);
	}
	else if ((*li_b)->next && (int)(*li_b)->content < (int)(*li_b)->next->content && (int)(*li_b)->content > li_min)
		swap_list(*li_b, 2);
	initialised = 1;	
}

void	drain_by_max(t_list **li_b, t_list **li_a, int size)
{
	t_list *tmp;
	(void)size;

	while(*li_b)
	{
		//tmp = chunk_max(*li_b, size);
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

void	drain_by_min(t_list **li_b, t_list **li_a, int size)
{
	t_list *tmp;

	while(*li_b)
	{
		tmp = chunk_min(*li_b, size);
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

int		max_arr(int *arr, int size)
{
	int max;
	int i;

	i = 0;
	max  = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int		count_sort(t_list *li)
{
	int size;
	int *arr;
	int i;
	
	size  = ft_lstsize(li);
	if (!(arr = malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i++] = (int)li->content;
		li = li->next;
	}
	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] != max_arr(arr, i + 1))
			break;
		i--;
	}
	free(arr);
	return (i+ 1);
}




void	divide_from_median(t_list **li_a, t_list **li_b)
{
	t_list	*list_inf;
	int size;

	size = ft_lstsize(*li_a);

	while (ft_lstsize(*li_a) > size / 2)
	{
		list_inf = list_min(*li_a);
		while (*li_a != list_inf)
		{
				if (optimized_shift(*li_a, list_inf))
				{
					g_accumulator++;
					shift_up(li_a, 1);
				}	
				else
				{
					g_accumulator++;
					shift_down(li_a, 1);
				}
		}
		g_accumulator++;
		transfer_top(li_a, li_b, 1);
	}
}

void	sort_3_head(t_list **li, int verbose);
void	rev_sort_3_head(t_list **li, int verbose);
int		chunk_is_sort(t_list *li, int n);

int	chunk_is_sort(t_list *li, int n)
{
	int		sens;

	if (ft_lstsize(li) <= 1)
		return (1);
	while (li->next && (int)li->content == (int)li->next->content)
		li = li->next;
	if (li->next == NULL)
		return (1);
	sens = (int)li->next->content > (int)li->content ? 1 : 0;
	while (n--&& li && li->next)
	{
		
		if (sens && (int)li->next->content < (int)li->content)
			return (0);
		if (!sens && (int)li->next->content > (int)li->content)
			return (0);
		/*
		if ((int)li->next->content < (int)li->content)
			return (0);
		*/
		li = li->next;
	}
	if (sens == 0)
		return (-1);
	else
		return (1);
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


t_list	*find_median_initial(t_list *li)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		inf;
	int		sup;

	tmp = li;
	while (tmp)
	{
		inf = 0;
		sup = 0;
		tmp2 = li;
		while (tmp2)
		{
			if ((int)tmp->content < (int)tmp2->content)
				sup++;
			if ((int)tmp->content > (int)tmp2->content)
				inf++;
			tmp2 = tmp2->next;
		}
		if (inf <= ft_lstsize(li) / 2 && sup <= ft_lstsize(li) / 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	divide_list(t_list **li_a, t_list **li_b);

void	divide_list(t_list **li_a, t_list **li_b)
{
	int median;
	int	size;

	size = ft_lstsize(*li_a);
	median = (int)find_median(*li_a)->content;
	while (size--)
	{
		if (median < (int)(*li_a)->content)
			transfer_top(li_a, li_b, 1);
		shift_up(li_a, 1);
	}
}

t_list	*pivot_list(t_list *li, int n);
t_list	*find_chunk_median(t_list *li, int size);

t_list	*find_chunk_median(t_list *li, int size)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		n;
	int		inf;
	int		sup;

	n = size;
	tmp = li;
	while (n-- && tmp)
	{
		inf = 0;
		sup = 0;
		tmp2 = li;
		while (tmp2)
		{
			if ((int)tmp->content < (int)tmp2->content)
				sup++;
			if ((int)tmp->content > (int)tmp2->content)
				inf++;
			tmp2 = tmp2->next;
		}
		if (sup >= size / 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*pivot_list(t_list *li, int n)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		inf;
	int		sup;

	tmp = li;
	while (tmp)
	{
		inf = 0;
		sup = 0;
		tmp2 = li;
		while (tmp2)
		{
			if ((int)tmp->content < (int)tmp2->content)
				sup++;
			if ((int)tmp->content > (int)tmp2->content)
				inf++;
			tmp2 = tmp2->next;
		}
		if (inf <= ft_lstsize(li) / n && sup <= (n - 1) * ft_lstsize(li) / n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}


t_list	*chunk_max(t_list *li, int size);
t_list	*chunk_min(t_list *li, int size);

t_list	*chunk_min(t_list *li, int size)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li && size--)
	{
		tmp = li;
		while (tmp)
		{
			if ((int)res->content > (int)tmp->content)
				res = tmp;
			tmp = tmp->next;
		}
		li = li->next;
	}
	/*
	if (res != NULL)
		res->next = NULL;
	*/
	return (res);
}

t_list	*chunk_max(t_list *li, int size)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li && size--)
	{
		tmp = li;
		while (tmp)
		{
			if ((int)res->content < (int)tmp->content)
				res = tmp;
			tmp = tmp->next;
		}
		li = li->next;
	}
	return (res);
}

int		lst_cmp(t_list *li_a, t_list *li_b);

int	lst_cmp(t_list *li_a, t_list *li_b)
{
	if (ft_lstsize(li_a) != ft_lstsize(li_b))
		return (0);
	while (li_a && li_b)
	{
		if ((int)li_a->content != (int)li_b->content)
			return (0);
		li_b = li_b->next;
		li_a = li_a->next;
	}
	return (1);
}


void	visual_list(t_list *li)
{
	int	n;

	while (li != NULL)
	{
		n = (int)li->content;
		while (n--)
			ft_putchar_fd('_', 1);
		ft_putchar_fd('\n', 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

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

int is_3_last_order_init(t_list *li_b, t_list *chmax, t_list *prelast, t_list *preprelast)
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


/*
	while (*li_a != list_inf)
		{
				
				if (optimized_shift(*li_a, list_inf))
				{
					printf("ra\n");
					count++;
					shift_up(li_a);
				}	
				else
				{
					printf("rra\n");
					count++;
					shift_down(li_a);
				}
				}	
	*/


/*
void	process(t_list **li_a, t_list **li_b)
{
	t_list	*list_inf;
	t_list	*list_median;
	int size;
	int count;

	list_median = find_median(*li_a);
	count = 0;
	while (!lst_is_sort(*li_a))// && ft_lstsize(*li_a) > 2)//lst_is_sort(*li_a) < 1)// || *li_a != NULL)
	{
		list_inf = list_min(*li_a);
		
		while (*li_a != list_inf)
		{
				
				if (optimized_shift(*li_a, list_inf))
				{
					printf("ra\n");
					count++;
					shift_up(li_a);
				}	
				else
				{
					printf("rra\n");
					count++;
					shift_down(li_a);
				}
				
				
		}
		
		printf("pa\n");
		count++;
		transfer_top(li_a, li_b);
	
	}
	if (lst_is_sort(*li_a) < 1)
	{
		count++;
		printf("sa\n");
		swap_list(*li_a);
	}
	
	
	while (*li_b != NULL)
	{
		printf("pb\n");
		count++;
		transfer_top(li_b, li_a);
	}
	printf("OPERATION_COUNT => [%d]\n", count);
}
*/

//bigprocess
/*
		ft_putstr_fd("_________________________________________________\n", 1);
		ft_putstr_fd("ledger->n = ", 1);
		ft_putnbr_fd(ledger->n, 1);
		ft_putstr_fd("\n", 1);
		display_list(temp);
		ft_lstclear(&temp, ft_del);
		*/
		

	/*
			//if (dist_to_lst(*li_b, ch_min) < dist_to_lst(*li_b, ch_max))
			if(0)
			{
				reminder++;
				treat_min(li_b, li_a, ch_min);
				ft_lstpop(&temp);
			}	
			else
			{
				treat_max(li_b, li_a, ch_max);
				ft_lstshift(&temp);
			}
			*/














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

			/*
			ft_putstr_fd("**********************************************************************\n", 1);
			display_list(state->li_b);
			ft_putstr_fd("----------------------------------------------------------------------\n", 1);
			display_list(temp);
			ft_putstr_fd("**********************************************************************\n\n\n", 1);
			*/

/*
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
				//treat_min(&state->li_b, &state->li_a, ch_min, state);
				ft_lstpop(&temp);
			}	
			else
			{
				//treat_max(&state->li_b, &state->li_a, ch_max, state);
				ft_lstshift(&temp);
			}
		}
		while (reminder--)
			shift_up(&state->li_a, 1, state);
		ledger = ledger->next;
	}
	
}
*/