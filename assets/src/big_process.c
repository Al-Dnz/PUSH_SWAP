#include "header.h"

void	adjust_list_b(t_list **li_b, int first)
{
	static int initialised;
	static int	li_min;
	static int	li_max;

	if (initialised == 0)
	{
		li_min = (int)(*li_b)->content;
		li_max = (int)(*li_b)->content;
	}
	if ((int)(*li_b)->content > li_max)
		li_max = (int)(*li_b)->content;
	else if ((int)(*li_b)->content < li_min && first)
	{
		li_min = (int)(*li_b)->content;
		shift_down(li_b, 2);
	}
	else if ((*li_b)->next && (int)(*li_b)->content < (int)(*li_b)->next->content && (int)(*li_b)->content > li_min)
		swap_list(*li_b, 2);
	initialised = 1;	
}

void	drain_by_max(t_list **li_b, t_list **li_a, int size)
{
	t_list *tmp;
	while(*li_b)
	{
		tmp = chunk_max(*li_b, size);
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if ((*li_b)->next == tmp)
		{
			swap_list(*li_b, 2);
			transfer_top(li_b, li_a, 2);
		}	
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}

void	drain_by_min(t_list **li_b, t_list **li_a, int size)
{
	t_list *tmp;
	while(*li_b)
	{
		tmp = chunk_min(*li_b, size);
		if  (*li_b == tmp)
			transfer_top(li_b, li_a, 2);
		else if ((*li_b)->next == tmp)
		{
			swap_list(*li_b, 2);
			transfer_top(li_b, li_a, 2);
		}	
		else if (optimized_shift(*li_b, tmp))	
			shift_up(li_b, 2);
		else
			shift_down(li_b, 2);
	}
}




int		max_arr(int *arr, int size)
{
	int max;
	int i;

	i = 0;
	max  = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int		count_sort(t_list *li)
{
	int size;
	int *arr;
	int i;
	
	size  = ft_lstsize(li);
	if (!(arr = malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i++] = (int)li->content;
		li = li->next;
	}
	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] != max_arr(arr, i + 1))
			break;
		i--;
	}
	free(arr);
	return (i+ 1);
}

void	process_100(t_list **li_a, t_list **li_b)
{
	printf("PROCESS_100\n");
	t_register *ledger;

	ledger = NULL;
	
	brut_sort(li_a, li_b, &ledger);
	process_3(li_a, li_b);
	//drain_by_max(li_b, li_a);
	ft_putstr_fd("--------\n", 1);
	ft_putstr_fd("chunk_median --> ", 1);
	//display_list(find_chunk_median(*li_b, 5));
	ft_putnbr_fd((int)find_chunk_median(*li_b, 7)->content, 1);
	ft_putstr_fd("\n*******\n", 1);
	
	
}


//lst_is_sort(*li_a) < 1)// || 

/*


if (size < 4)
	{
		process_chunk_head(li_1, li_2, size, sens);
		return;
	}

//else
			//	drain_by_max(li_b, li_a);
			register_pop(&ledger);
			ft_putstr_fd("\n*******\n", 1);
			display_register(ledger);
			ft_putstr_fd("\n*******\n", 1);
			//process_chunk(li_b, li_a, (int)ledger->n, 1);
*/