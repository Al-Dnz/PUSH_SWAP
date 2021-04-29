#include "header.h"

void	display_list(t_list *li)
{
	while (li != NULL)
	{
		printf("[%d]\n-----------\n", (int)li->content);
		li = li->next;
	}
	printf("NULL\n===========\n");
}

// sa/sb/ss

void 	swap_list(t_list *li)
{
	void	*tmp;

	tmp = li->content;
	li->content = li->next->content;
	li->next->content = tmp;
	ft_del(tmp);
}

// ra/rb/rr

void	shift_up(t_list **li)
{
	t_list	*new;
	void *tmp;

	tmp = ft_lstshift(*li);
	new  = ft_lstnew(tmp);
	ft_lstadd_front(li, new);
	ft_del(tmp);
}

// rra/rrb/rrr

void	shift_down(t_list **li)
{
	t_list	*new;
	void	*tmp;

	tmp = ft_lstpop(li);
	new = ft_lstnew(tmp);
	ft_lstadd_back(li, new);
	ft_del(tmp);
}

// pa/pb

void	transfer_top(t_list **li_a, t_list **li_b)
{
	void	*tmp;

	tmp = ft_lstpop(li_a);
	ft_lstadd_front(li_b, ft_lstnew(tmp));
	ft_del(tmp);
}
