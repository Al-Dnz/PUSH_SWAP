/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:17:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/06 16:17:17 by adenhez          ###   ########.fr       */
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
	t_list			*li_a;
	t_list			*li_b;
	t_register	*seq;
};
typedef struct s_state	t_state;

int		arg_error(int argc, char **argv);
void	list_generator(t_list **li, char **tab, int *error);
int		duplicate_error(t_list *li);
void	parser(t_list **li, int argc, char **argv, int *error);

void	swap_list(t_list *li, int mode, t_state *state);
void	shift_up(t_list **li, int mode, t_state *state);
void	shift_down(t_list **li, int mode, t_state *state);
void	transfer_top(t_list **li_1, t_list **li_2, int mode, t_state *state);

void	double_swap_list(t_list *li_a, t_list *li_b, int mode, t_state *state);
void	double_shift_up(t_list **li_a, t_list **li_b, int mode, t_state *state);
void	double_shift_down(t_list **li_a, t_list **li_b, int mode, t_state *state);

int		lst_is_sort(t_list *li);
int		lst_cmp(t_list *li_a, t_list *li_b);
void	display_list(t_list *li);
void	visual_list(t_list *li);
t_list	*list_min(t_list *li);
t_list	*list_max(t_list *li);
void	lst_cpy(t_list **dest, t_list *li, int size);

void	get_instruct(t_list **li_a, t_list **li_b, int *error);
void	switcher(char *str, t_list **li_a, t_list **li_b);
int		lst_checker(t_list **li_a, t_list **li_b);
int		quit(t_list **li_a, t_list **li_b, int mode);

t_list	*find_median(t_list *li);

void	flag_parser(t_state *state, int argc, char **argv);

int		optimized_shift(t_list *li, t_list *list_inf);
int		dist_to_lst(t_list *li, t_list *list);

void	sort_by_push(t_list **li_a, t_list **li_b, t_state *state);
void	bring_back(t_list **li_a, t_list **li_b, t_state *state);
void 	insertion_sort(t_list **li, t_state *state);
void	switch_process(t_state *state);
void	switch_push_swap(t_list **li_a, t_list **li_b);

void	process_2(t_state *state);
void	process_3(t_state *state);
void	process_5(t_state *state);
void	process_100(t_state *state);

void	brut_sort(t_list **li_a, t_list **li_b, t_register **ledger, t_state *state);

void	reduce_by_med(t_list **li_1, t_list **li_2, int sens, int size, t_register **temp);

void	process_chunk_head(t_list **li_1, t_list **li_2, int size, int sens);
void	process_chunk(t_list **li_1, t_list **li_2, int size, int sens);

void		register_add_back(t_register **alst, t_register *new);
void		register_add_front(t_register **alst, t_register *new);
void		register_clear(t_register **lst);
void		register_pop(t_register **head_ref);
t_register	*register_new(int n);
t_register	*register_last(t_register *lst);
void		display_register(t_register *li);
void		read_seq(t_register *reg);

void 		list_merge_sort(t_list** head_ref);

#endif
