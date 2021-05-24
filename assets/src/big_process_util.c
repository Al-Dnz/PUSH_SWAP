#include "header.h"

void	brut_sort(t_list **li_a, t_list **li_b, t_register **ledger)
{
	t_list	*pivot;
	int		first;
	int		size;
	int		size2;
	int		n;

	first = 1;
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
				//if (first == 1)
					adjust_list_b(li_b, first);
				n++;
			}
			shift_up(li_a, 1);
		}
		first = 0;
		register_add_front(ledger, register_new(n));
		size2 = ft_lstsize(*li_a);
	}
}

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

