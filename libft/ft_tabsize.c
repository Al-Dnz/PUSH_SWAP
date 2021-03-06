/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:37:46 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/27 15:45:22 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabsize(char **tab)
{
	int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}
