#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*li_a;
	t_list	*li_b;
	int		error;

	li_a = NULL;
	li_b = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	parser(&li_a, argc, argv);
	display_list(li_a);
	display_list(li_b);
	//printf("=>%d\n", lst_cmp(li_a, li_b));
	//printf("=>%d\n", lst_is_sort(li_a));
	//ft_lstclear(&li_a, &ft_del);
	get_instruct(&li_a, &li_b, &error);

	if (!error)
	{
		if (lst_checker(&li_a, &li_b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	

	ft_lstclear(&li_a, &ft_del);
	ft_lstclear(&li_b, &ft_del);
	return (1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

	//shift_up(&li);
	//display_list(li);

	/*
	t_list *li2 = NULL;
	li2 = ft_lstnew((void*)55);
	ft_lstadd_back(&li2, ft_lstnew((void*)33));
	ft_lstadd_back(&li2, ft_lstnew((void*)99));
	ft_lstadd_back(&li2, ft_lstnew((void*)111));
	display_list(li2);

	printf("\n======================================\n\n");

	printf("\n======================================\n\n");
	transfer_top(&li, &li2);
	display_list(li);
	display_list(li2);

	ft_lstclear(&li, &ft_del);
	ft_lstclear(&li2, &ft_del);
	*/
