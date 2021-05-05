#include "header.h"



t_list	*list_min(t_list *li)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li)
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

t_list	*list_max(t_list *li)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li)
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


int	optimized_shift(t_list *li, t_list *list_inf)
{
	int before;
	int	after;

	before = 0;
	after = 0;
	while (li != list_inf)
	{
		before++;
		li = li->next;
	}
	if (li)
		li = li->next;
	while (li)
	{
		after++;
		li = li->next;
	}
	if (before <= after)
		return (0);
	else
		return (1);
}	


void	sort_by_push(t_list **li_a, t_list **li_b)
{
	t_list	*list_inf;

	while (ft_lstsize(*li_a) > 3)
	{
		list_inf = list_min(*li_a);
		while (*li_a != list_inf)
		{
				if (optimized_shift(*li_a, list_inf))
				{
					printf("ra\n");
					g_accumulator++;
					shift_up(li_a);
				}	
				else
				{
					printf("rra\n");
					g_accumulator++;
					shift_down(li_a);
				}
		}
		printf("pa\n");
		g_accumulator++;
		transfer_top(li_a, li_b);
	}
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
					printf("ra\n");
					g_accumulator++;
					shift_up(li_a);
				}	
				else
				{
					printf("rra\n");
					g_accumulator++;
					shift_down(li_a);
				}
		}
		printf("pa\n");
		g_accumulator++;
		transfer_top(li_a, li_b);
	}
}

void	bring_back(t_list **li_a, t_list **li_b)
{
	while (*li_b != NULL)
	{
		printf("pb\n");
		g_accumulator++;
		transfer_top(li_b, li_a);
	}

}

void insertion_sort(t_list **li)
{
		while (lst_is_sort(*li) < 1)
		{
			if ((int)(*li)->content > (int)(*li)->next->content)
			{
				g_accumulator++;
				printf("sa\n");
				swap_list(*li);
			}
			g_accumulator++;
			printf("rra\n");
			shift_down(li);
		}
}	

void	process(t_list **li_a, t_list **li_b)
{
	g_accumulator = 0;
	switch_push_swap(li_a, li_b);
	printf("OPERATION_COUNT => [%d]\n", g_accumulator);
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