#include "header.h"

int		find_med_of_med(t_list *li)
{
	t_list *temp;
	int	med;
	int res;

	temp = NULL;
	med = (int)find_median(li)->content;
	while (li)
	{
		if ((int)li->content < med)
			ft_lstadd_back(&temp, ft_lstnew(li->content));
		li = li->next;
	}
	res = (int)find_median(temp)->content;
	ft_lstclear(&temp, &ft_del);
	return (res);
}

void	adjust_list_b(t_list **li_b, int med_of_med, int first)
{
	
	if ((int)(*li_b)->content <= med_of_med && first)
		shift_down(li_b, 2);
	//else if(*li_b && (*li_b)->next && (int)(*li_b)->content < (int)(*li_b)->next->content)
	//	swap_list(*li_b, 2);

}

void	brut_sort(t_list **li_a, t_list **li_b, t_register **ledger)
{
	t_list	*pivot;
	int		first;
	int		size;
	int		size2;
	int		med_of_med;
	int		n;

	first = 1;
	size2 = ft_lstsize(*li_a);
	while (size2 > 3)
	{
		pivot = find_median(*li_a);
		size = ft_lstsize(*li_a);
		n = 0;
		med_of_med = find_med_of_med(*li_a);
		while (size--)
		{
			
			if ((int)(*li_a)->content < (int)pivot->content)
			{
				transfer_top(li_a, li_b, 1);
				adjust_list_b(li_b, med_of_med, first);
				//if (first == 1)
					//adjust_list_b(li_b, first);
				n++;
			}
			shift_up(li_a, 1);
		}
		first = 0;
		register_add_front(ledger, register_new(n));
		size2 = ft_lstsize(*li_a);
	}
}

