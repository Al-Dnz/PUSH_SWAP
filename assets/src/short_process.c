#include "header.h"

void	process_2(t_state *state)
{
	if (lst_is_sort(state->li_a) < 1)
		swap_list(state->li_a, 1, state);
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

void	process_3(t_state *state)
{
	int	sens;
	
	if (lst_is_sort(state->li_a) == 1)
		return ;
	if (forbidden_seq(state->li_a))
		swap_list(state->li_a, 1, state);
	sens = optimized_shift(state->li_a, list_min(state->li_a));
	while (lst_is_sort(state->li_a) < 1)
	{
		if(sens == 0)
			shift_down(&state->li_a, 1, state);
		else
			shift_up(&state->li_a, 1, state);
	}
}

void	process_5(t_state *state)
{
	sort_by_push(&state->li_a, &state->li_b, state);
	process_3(state);
	bring_back(&state->li_a, &state->li_b, state);
}