/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:17:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/30 22:18:33 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../libft/libft.h"
# include <stdio.h>

struct	s_stack
{
	int				n;
	struct s_stack	*next;
};
typedef struct s_stack	t_stack;

int		arg_error(int argc, char **argv);
void	list_generator(t_list **li, char **tab);
void	parser(t_list **li, int argc, char **argv);
void	display_list(t_list *li);
void	swap_list(t_list *li);
void	shift_up(t_list **li);
void	shift_down(t_list **li);
void	transfer_top(t_list **li_a, t_list **li_b);
int		lst_is_sort(t_list *li);
int		lst_cmp(t_list *li_a, t_list *li_b);
void	get_instruct(t_list **li_a, t_list **li_b, int *error);
void	switcher(char *str, t_list **li_a, t_list **li_b);
int		lst_checker(t_list **li_a, t_list **li_b);

#endif
