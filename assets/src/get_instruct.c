/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez<adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:38:50 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/04 13:49:05 by adenhez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	lst_checker(t_list **li_a, t_list **li_b)
{
	if (ft_lstsize(*li_b) == 0 && lst_is_sort(*li_a) > 0)
		return (1);
	return (0);
}

int	auth_str(char *str)
{
	static char	*arr[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
"rr", "rra", "rrb", "rrr"};

	if (ft_str_index(str, arr) == -1)
		return (0);
	return (1);
}

void	get_instruct(t_list **li_a, t_list **li_b, int *error)
{
	char	*str;
	char	**tab;
	int		ret;

	tab = NULL;
	ret = 1;
	while (ret != 0)
	{
		str = NULL;
		ret = get_next_line(0, &str);
		if (!ft_strchart(str, " \n") && ft_strlen(str))
		{
			tab = ft_split(str, " ");
			if (ft_tabsize(tab) > 1 || !auth_str(str))
			{
				*error = 1;
				ret = 0;
			}
			else
				switcher(str, li_a, li_b);
			ft_free_tab(tab);
		}
		ft_strclr(&str);
	}
}
