/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:17:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/14 23:02:58 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

///////////////////
# include <stdio.h>
int	g_accumulator;
///////////////////

typedef struct s_reg
{
	int				n;
	struct s_reg	*next;
}								t_reg;

typedef struct s_tb_1
{
	int		first;
	int		size;
	int		size2;
	int		med_of_med;
	int		n;
}								t_tb_1;

typedef struct s_state
{
	t_list	*li_a;
	t_list	*li_b;
	t_reg	*seq;
}								t_state;

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
void	double_shift_down(t_list **li_a, t_list **li_b,
			int mode, t_state *state);

int		lst_is_sort(t_list *li);
int		lst_cmp(t_list *li_a, t_list *li_b);
t_list	*list_min(t_list *li);
t_list	*list_max(t_list *li);
void	lst_cpy(t_list **dest, t_list *li, int size);

void	display_list(t_list *li);
void	visual_list(t_list *li);

void	get_instruct(t_list **li_a, t_list **li_b, int *error);
void	switcher(char *str, t_list **li_a, t_list **li_b);
int		lst_checker(t_list **li_a, t_list **li_b);
int		quit(t_list **li_a, t_list **li_b, int mode, t_state *state);

t_list	*find_median(t_list *li);

void	flag_parser(t_state *state, int argc, char **argv);

int		optimized_shift(t_list *li, t_list *list_inf);
int		dist_to_lst(t_list *li, t_list *list);

void	sort_by_push(t_list **li_a, t_list **li_b, t_state *state);
void	bring_back(t_list **li_a, t_list **li_b, t_state *state);
void	insertion_sort(t_list **li, t_state *state);
void	switch_process(t_state *state);
void	switch_push_swap(t_list **li_a, t_list **li_b);

void	process_2(t_state *state);
void	process_3(t_state *state);
void	process_5(t_state *state);
void	process_100(t_state *state);

void	brut_sort(t_list **li_a, t_list **li_b,
			t_reg **ledger, t_state *state);

void	reduce_by_med(t_list **li_1, t_list **li_2,
			int sens, int size, t_reg **temp);

void	process_chunk_head(t_list **li_1, t_list **li_2, int size, int sens);
void	process_chunk(t_list **li_1, t_list **li_2, int size, int sens);

void	register_add_back(t_reg **alst, t_reg *new);
void	register_add_front(t_reg **alst, t_reg *new);
void	register_clear(t_reg **lst);
void	register_pop(t_reg **head_ref);
t_reg	*register_new(int n);

t_reg	*register_last(t_reg *lst);
void	display_register(t_reg *li);
int		read_seq(t_reg *reg);

void	list_merge_sort(t_list **head_ref);

void	sort_3_head(t_list **li, int verbose, t_state *state);
#endif
