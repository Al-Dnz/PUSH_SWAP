/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_util_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:22:04 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 13:40:33 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_reg	*register_last(t_reg *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	read_seq(t_reg *reg)
{
	int			n;
	static char	*arr[12] = {"", "sa", "sb", "ss", "pb", "pa", "rra", "rrb",
"rrr", "ra", "rb", "rr"};

	n = 0;
	while (reg != NULL)
	{
		ft_putstr_fd(arr[reg->n], 1);
		ft_putstr_fd("\n", 1);
		n++;
		reg = reg->next;
	}
	return (n);
}

void	display_register(t_reg *li)
{
	while (li != NULL)
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd((int)li->n, 1);
		ft_putstr_fd("]->", 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}
