#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*li_1;
	t_list	*li_2;
	//char	*str;

	li_1 = NULL;
	li_2 = NULL;
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	parser(&li_1, argc, argv);
	display_list(li_1);

	li_2 = ft_lstnew((void*)1);
	ft_lstadd_back(&li_2, ft_lstnew((void*)2));
	ft_lstadd_back(&li_2, ft_lstnew((void*)3));
	display_list(li_2);
	printf("\n======================================\n\n");
	printf("=>%d\n", lst_cmp(li_1, li_2));
	//printf("=>%d\n", lst_is_sort(li_1, &ft_is_supequal));
	//ft_lstclear(&li_1, &ft_del);

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
	transfer_top(&li, &li2);
	display_list(li);
	display_list(li2);

	ft_lstclear(&li, &ft_del);
	ft_lstclear(&li2, &ft_del);
	*/
