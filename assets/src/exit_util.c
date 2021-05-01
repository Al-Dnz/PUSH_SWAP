/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:14:13 by alexdnz           #+#    #+#             */
/*   Updated: 2021/05/01 18:29:16 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	quit(t_list **li_a, t_list **li_b, int error)
{
	if (error)
		ft_putstr_fd("Error\n", 1);
	ft_lstclear(li_a, &ft_del);
	ft_lstclear(li_b, &ft_del);
	exit(error);
	return (error);
}
