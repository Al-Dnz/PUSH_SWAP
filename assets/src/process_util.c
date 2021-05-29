#include "header.h"


t_list	*find_median(t_list *li)
{
	t_list *temp;
	t_list	*res;
	int		size;
	int		i;
	
	size = ft_lstsize(li);
	i = 0;
	temp = NULL;
	lst_cpy(&temp, li, size);
	list_merge_sort(&temp);
	while (i++ <= size / 2)
		temp = temp->next;
	res = ft_lstnew(NULL);
	res->content = temp->content;
	ft_lstclear(&temp, ft_del);
	return (res);
}




int	optimized_shift(t_list *li, t_list *list_inf)
{
	int before;
	int	after;

	before = 0;
	after = 0;
	while ((int)li->content != (int)list_inf->content)
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


int	dist_to_lst(t_list *li, t_list *list)
{
	int dist;

	dist = 0;
	while (li)
	{
		if ((int)li->content == (int)list->content)
			return (dist);
		dist++;
		li = li->next;
	}
	if (ft_lstsize(li) - dist + 1 < dist)
		return (ft_lstsize(li) - dist + 1);
	else
		return (dist);
}

void	bring_back(t_list **li_a, t_list **li_b)
{
	while (*li_b != NULL)
	{
		g_accumulator++;
		transfer_top(li_b, li_a, 2);
	}
}