#include "header.h"

void	process_2(t_list **li_a, t_list **li_b)
{
	(void)li_b;
	if (lst_is_sort(*li_a) < 1)
		swap_list(*li_a, 1);
}

int	forbidden_seq(t_list *li)
{
	t_list *temp;
	int	min;
	int max;
	int mid;

	min = (int)list_min(li)->content;
	max = (int)list_max(li)->content;
	temp = li;
	while (temp)
	{
		if ((int)(temp)->content != min && (int)(temp)->content != max)
			mid = (int)(temp)->content;
		temp = temp->next;
	}
	while (li && li->next)
	{
		if (((int)(li)->content == max && (int)(li)->next->content == mid) ||
				((int)(li)->content == mid && (int)(li)->next->content == min) ||
				((int)(li)->content == min && (int)(li)->next->content == max))
				return (1);
		li = li->next;
	}
	return (0);
}

void	process_3(t_list **li_a, t_list **li_b)
{
	(void)li_b;
	int	sens;
	
	if (forbidden_seq(*li_a))
		swap_list(*li_a, 1);
	sens = optimized_shift(*li_a, list_min(*li_a));
	while (lst_is_sort(*li_a) < 1)
	{
		if(sens == 0)
			shift_down(li_a, 1);
		else
			shift_up(li_a, 1);
	}
}

void	process_5(t_list **li_a, t_list **li_b)
{
	sort_by_push(li_a, li_b);
	process_3(li_a, li_b);
	bring_back(li_a, li_b);
}