#include "header.h"

void	sort_by_push(t_list **li_a, t_list **li_b, t_state *state)
{
	t_list	*list_inf;

	while (ft_lstsize(*li_a) > 3)
	{
		list_inf = list_min(*li_a);
		while (*li_a != list_inf)
		{
				if (optimized_shift(*li_a, list_inf))
				{
					g_accumulator++;
					shift_up(li_a, 1, state);
				}	
				else
				{
					g_accumulator++;
					shift_down(li_a, 1, state);
				}
		}
		g_accumulator++;
		transfer_top(li_a, li_b, 1, state);
	}
}

void insertion_sort(t_list **li, t_state *state)
{
		while (lst_is_sort(*li) < 1)
		{
			if ((int)(*li)->content > (int)(*li)->next->content)
			{
				g_accumulator++;
				printf("sa\n");
				swap_list(*li, 1, state);
			}
			g_accumulator++;
			printf("rra\n");
			shift_down(li, 1, state);
		}
}	

void	switch_process(t_state *state)
{
	g_accumulator = 0;
	int size;
	
	size = ft_lstsize((state->li_a));
	if (lst_is_sort((state->li_a)) == 1 || size == 1)
		return ;
	if (size == 2)
	{
		process_2(state);
		return;
	}	
	if (size == 3)
	{
		process_3(state);
		return;
	}
	if (size < 60)
	{
		process_5(state);
		return;
	}
	if (size <= 1000)
	{
		process_100(state);
		return;
	}
	
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