/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:42:01 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/14 23:06:39 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_state	state;
	int		error;

	state.li_a = NULL;
	state.li_b = NULL;
	state.seq = NULL;
	error = 0;
	if (argc == 1)
		return (0);
	if (arg_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	parser(&state.li_a, argc, argv, &error);
	if (error)
		return (quit(&state.li_a, &state.li_b, error, &state));
	switch_process(&state);
	read_seq(state.seq);
	return (quit(&state.li_a, &state.li_b, error, &state));
}
