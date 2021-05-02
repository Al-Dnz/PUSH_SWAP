/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:17:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/02 15:11:12 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <limits.h>


///////////////////
#include <stdio.h>
///////////////////

struct	s_stack
{
	int				n;
	struct s_stack	*next;
};
typedef struct s_stack	t_stack;

struct	s_state
{
	int				verbose;
	int				color;
};
typedef struct s_state	t_state;

int		arg_error(int argc, char **argv);
void	list_generator(t_list **li, char **tab, int *error);
int		duplicate_error(t_list *li);
void	parser(t_list **li, int argc, char **argv, int *error);
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
int		quit(t_list **li_a, t_list **li_b, int mode);

t_list	*find_median(t_list *li);
void	divide_list(t_list **li_a, t_list **li_b);
void	flag_parser(t_state *state, int argc, char **argv);
void	process(t_list **li_a, t_list **li_b);


#endif
