/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:41:08 by alexdnz           #+#    #+#             */
/*   Updated: 2021/05/02 13:23:41 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	flag_parser(t_state *state, int argc, char **argv)
{
	int	i;

	state->verbose = 0;
	state->color = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp("-v", argv[i]) == 0)
			state->verbose = 1;
		if (ft_strcmp("-c", argv[i]) == 0)
			state->color = 1;
		if (!ft_strcmp("-c", argv[i]) || !ft_strcmp("-v", argv[i]))
		{
			argv[i][0] = ' ';
			argv[i][1] = ' ';
		}
		i++;
	}
}
