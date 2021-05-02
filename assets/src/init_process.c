/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:13:47 by alexdnz           #+#    #+#             */
/*   Updated: 2021/05/02 00:21:53 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	divide_list(t_list **li_a, t_list **li_b)
{
	int median;
	int	size;

	size = ft_lstsize(*li_a);
	median = (int)find_median(*li_a)->content;
	while (size--)
	{
		if (median < (int)(*li_a)->content)
			transfer_top(li_a, li_b);
		shift_up(li_a);
	}
}

t_list	*find_median(t_list *li)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		inf;
	int		sup;

	tmp = li;
	while (tmp)
	{
		inf = 0;
		sup = 0;
		tmp2 = li;
		while (tmp2)
		{
			if ((int)tmp->content < (int)tmp2->content)
				sup++;
			if ((int)tmp->content > (int)tmp2->content)
				inf++;
			tmp2 = tmp2->next;
		}
		if (inf <= ft_lstsize(li) / 2 && sup <= ft_lstsize(li) / 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
