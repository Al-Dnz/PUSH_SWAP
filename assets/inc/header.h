/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdnz <alexdnz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:17:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/16 17:38:36 by alexdnz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <limits.h>


///////////////////
#include <stdio.h>
int g_accumulator;
///////////////////

struct	s_register
{
	int					n;
	struct s_register	*next;
};
typedef struct s_register	t_register;

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

void	swap_list(t_list *li, int verbose);
void	shift_up(t_list **li, int verbose);
void	shift_down(t_list **li, int verbose);
void	transfer_top(t_list **li_a, t_list **li_b, int verbose);

void	double_swap_list(t_list *li_a, t_list *li_b, int verbose);
void	double_shift_up(t_list **li_a, t_list **li_b, int verbose);
void	double_shift_down(t_list **li_a, t_list **li_b, int verbose);


int		lst_is_sort(t_list *li);
int		lst_cmp(t_list *li_a, t_list *li_b);
void	get_instruct(t_list **li_a, t_list **li_b, int *error);
void	switcher(char *str, t_list **li_a, t_list **li_b);
int		lst_checker(t_list **li_a, t_list **li_b);
int		quit(t_list **li_a, t_list **li_b, int mode);

t_list	*find_median(t_list *li);
t_list	*find_chunk_median(t_list *li, int size);
void	divide_list(t_list **li_a, t_list **li_b);
void	flag_parser(t_state *state, int argc, char **argv);
void	process(t_list **li_a, t_list **li_b);

t_list	*list_min(t_list *li);
t_list	*list_max(t_list *li);
int	optimized_shift(t_list *li, t_list *list_inf);
void	divide_from_median(t_list **li_a, t_list **li_b);
void	sort_by_push(t_list **li_a, t_list **li_b);
void	bring_back(t_list **li_a, t_list **li_b);
void insertion_sort(t_list **li);
void	process(t_list **li_a, t_list **li_b);
void	switch_push_swap(t_list **li_a, t_list **li_b);

t_list	*pivot_list(t_list *li, int n);

void	process_2(t_list **li_a, t_list **li_b);
void	process_3(t_list **li_a, t_list **li_b);
void	process_5(t_list **li_a, t_list **li_b);
void	process_100(t_list **li_a, t_list **li_b);

void	process_chunk(t_list **li_1, t_list **li_2, int size, int sens);
void	sort_3_head(t_list **li, int verbose);
void	rev_sort_3_head(t_list **li, int verbose);

void	register_add_back(t_register **alst, t_register *new);

void	register_add_front(t_register **alst, t_register *new);
void	register_clear(t_register **lst);
void	register_pop(t_register **head_ref);
t_register	*register_new(int n);
void	display_register(t_register *li);

#endif
