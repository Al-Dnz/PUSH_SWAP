/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:13:29 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/16 17:56:17 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*li_a;
	t_list	*li_b;
	//t_state	state;
	int		error;

	li_a = NULL;
	li_b = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	/*
	flag_parser(&state, argc, argv);
	printf("-v => %d\n-c => %d\n", state.verbose, state.color);
	*/
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	parser(&li_a, argc, argv, &error);
	display_list(li_a);
	display_list(li_b);
	if (error)
		return (quit(&li_a, &li_b, error));
	ft_putstr_fd("median= ", 1);
	ft_putnbr_fd((int)find_median(li_a)->content, 1);
	int n = 3;
	printf("\npivot[%d] => %d\n", n ,(int)pivot_list(li_a, n)->content);
	ft_putstr_fd("\n", 1);
	//divide_list(&li_a, &li_b);
	process(&li_a, &li_b);

	display_list(li_a);
	display_list(li_b);

	printf("OPERATION_COUNT => [%d]\n", g_accumulator);
	return (quit(&li_a, &li_b, error));
}
