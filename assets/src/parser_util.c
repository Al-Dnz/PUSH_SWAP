/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:08:28 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/30 22:22:27 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		arg_error(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!ft_strchart(argv[i], " 0123456789"))
			return (1);
		i++;
	}
	return (0);
}

void	list_generator(t_list **li, char **tab)
{
	int		i;
	t_list	*temp;

	temp = NULL;
	i = 0;
	while (tab[i])
	{
		if (*li == NULL)
			*li = ft_lstnew((void*)ft_atoi(tab[i]));
		else
		{
			temp = ft_lstnew((void*)ft_atoi(tab[i]));
			ft_lstadd_back(li, temp);
		}
		i++;
	}
}

void	parser(t_list **li, int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;

	tab = NULL;
	i = 1;
	while (i < argc)
	{
		tab = ft_split(argv[i], " ");
		j = 0;
		list_generator(li, tab);
		ft_free_tab(tab);
		i++;
	}
}
