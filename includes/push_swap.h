/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:20:49 by marvin            #+#    #+#             */
/*   Updated: 2020/04/13 17:20:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

#include "forbidden.h"

typedef struct		s_stack
{
	int				*data;
	int				top;
}					t_stack;

typedef struct		s_info
{
	int				argc;
	int				count;
	char			*action;
	int				threemin[3];
	int				ind_maxb;
	int				ind_minb[2];
	int				median;
	int				filllevel;
	char			flag;

	int				ind_mina;
	int				ind_maxa;
	int				filltop_b;
}					t_info;

void	put_stacks(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	sortup_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	def_threemin(t_stack *stack_a, t_info *info);
void	def_median(t_stack *stack_a, t_info *info);

void	def_index_maxb(t_stack *stack_b, t_info *info);
void	def_index_minb(t_stack *stack_b, t_info *info);

char	check_sort_a(t_stack *stack_a);
char	check_sort_b(t_stack *stack_b);
void	depletion_b(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	fill_stack_b(t_stack *stack_a, t_stack *stack_b, t_info *info);

void	def_index_mina(t_stack *stack_a, t_info *info);
void	def_index_maxa(t_stack *stack_a, t_info *info);


/*
** def_data.c
*/
void	def_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	def_info(t_info *info, int argc);

/*
** sort_stack_a.c
*/
void	sort_a_1memb(t_stack *stack_a);
void	sort_a_2memb(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	sort_a_3memb(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	sort_a_4memb(t_stack *stack_a, t_stack *stack_b, t_info *info);
// void	sort_a_5memb(t_stack *stack_a, t_stack *stack_b, t_info *info);

/*
** sort_stack_b.c
*/
void	sort_b_2memb(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	sort_b_3memb(t_stack *stack_a, t_stack *stack_b, t_info *info);


/*
** stack_actions.c
*/
void	swap_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	swap_b(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	swap_ab(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	push_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	push_b(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rot_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rot_b(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rot_ab(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rotr_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rotr_b(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	rotr_ab(t_stack *stack_a, t_stack *stack_b, t_info *info);

/*
** manual_input.c
*/
void	manual_input(t_stack *stack_a, t_stack *stack_b, t_info *info);

#endif