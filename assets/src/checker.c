/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:20:21 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/07 10:43:30 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*li_a;
	t_list	*li_b;
	t_state	state;
	int		error;

	li_a = NULL;
	li_b = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	parser(&li_a, argc, argv, &error);
	//display_list(li_a);
	//display_list(li_b);
	if (error)
		return (quit(&li_a, &li_b, error, &state));
	get_instruct(&li_a, &li_b, &error);
	if (lst_checker(&li_a, &li_b) && !error)
		ft_putstr_fd("OK\n", 1);
	else if (!lst_checker(&li_a, &li_b) && !error)
		ft_putstr_fd("KO\n", 1);
	return (quit(&li_a, &li_b, error, &state));
}
