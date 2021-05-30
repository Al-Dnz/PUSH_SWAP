/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:14:13 by adenhez          #+#    #+#             */
/*   Updated: 2021/05/14 16:44:38 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	quit(t_list **li_a, t_list **li_b, int error)
{
	if (error)
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(li_a, &ft_del);
	ft_lstclear(li_b, &ft_del);
	exit(error);
	return (error);
}
