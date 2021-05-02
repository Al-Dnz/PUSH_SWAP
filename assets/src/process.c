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

void	process(t_list **li_a, t_list **li_b)
{
	t_list	*list_inf;
	int count;

//	list_min = NULL;
	count = 0;
	while (!lst_is_sort(*li_a))// && ft_lstsize(*li_a) > 2)//!lst_is_sort(*li_a))// || *li_a != NULL)
	{
		list_inf = list_min(*li_a);
		
		while (*li_a != list_inf)
		{
				count++;
				if (optimized_shift(*li_a, list_inf))
				{
					printf("ra\n");
					shift_up(li_a);
				}	
				else
				{
					printf("rra\n");
					shift_down(li_a);
				}
		}
		
		printf("pa\n");
		count++;
		transfer_top(li_a, li_b);
	
	}
	if (!lst_is_sort(*li_a))
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