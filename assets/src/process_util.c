#include "header.h"

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

t_list	*find_median(t_list *li)
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


int	dist_to_lst(t_list *li, t_list *list)
{
	int dist;

	dist = 1;
	while (li)
	{
		if (li == list)
			return (dist);
		dist++;
		li = li->next;
	}
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