#include "header.h"

void	treat_min(t_list **li_b, t_list **li_a, t_list *li_min)
{
	int sens;

	sens = optimized_shift(*li_b, li_min);
	while ((int)(*li_b)->content != (int)li_min->content)
	{
		if (sens == 0)
			shift_down(li_b, 2);
		else
			shift_up(li_b, 2);
	}
	transfer_top(li_b, li_a, 2);
	shift_down(li_a, 1);
}

void	treat_max(t_list **li_b, t_list **li_a, t_list *li_max)
{
	int sens;

	sens = optimized_shift(*li_b, li_max);
	while ((int)(*li_b)->content != (int)li_max->content)
	{
		if ( sens == 0)
			shift_down(li_b, 2);
		else
			shift_up(li_b, 2);
	}
	transfer_top(li_b, li_a, 2);
}


void	process_100(t_list **li_a, t_list **li_b)
{
	t_register *ledger;

	ledger = NULL;
	
	brut_sort(li_a, li_b, &ledger);
	process_3(li_a, li_b);
	//drain_by_max(li_b, li_a, 0);

	t_list *ch_min;
	t_list *ch_max;
	t_list *temp;
	temp = NULL;
	ch_min = NULL;
	ch_max = NULL;
	int reminder;
	int sens;

	while (ledger)
	{
		lst_cpy(&temp, *li_b, ledger->n);
		list_merge_sort(&temp);
		/*
		ft_putstr_fd("_________________________________________________\n", 1);
		ft_putstr_fd("ledger->n = ", 1);
		ft_putnbr_fd(ledger->n, 1);
		ft_putstr_fd("\n", 1);
		display_list(temp);
		ft_lstclear(&temp, ft_del);
		*/
		
		reminder = 0;
		sens = 0;

		
		while (temp)
		{
			ch_min = temp;
			ch_max = ft_lstlast(temp);
			
			sens = optimized_shift(*li_b, ch_max);
			while ((int)(*li_b)->content != (int)ch_max->content)
			{
				if ((int)(*li_b)->content == (int)ch_min->content)
				{
					reminder++;
					transfer_top(li_b, li_a, 2);
					shift_down(li_a, 1);
					temp = temp->next;
				}
				else if (sens == 0)
					shift_down(li_b, 2);
				else
					shift_up(li_b, 2);
			}
			transfer_top(li_b, li_a, 2);
			ft_lstshift(&temp);
			

			/*
			//if (dist_to_lst(*li_b, ch_min) < dist_to_lst(*li_b, ch_max))
			if(0)
			{
				reminder++;
				treat_min(li_b, li_a, ch_min);
				ft_lstpop(&temp);
			}	
			else
			{
				treat_max(li_b, li_a, ch_max);
				ft_lstshift(&temp);
			}
			*/
		
		}
		while (reminder--)
			shift_up(li_a, 1); 
	
		ledger = ledger->next;
	}
}
