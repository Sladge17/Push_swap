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
}					t_info;


void	def_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	def_info(t_info *info, int argc);
void	put_stacks(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	sortup_a(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	def_threemin(t_stack *stack_a, t_info *info);

void	def_index_maxb(t_stack *stack_b, t_info *info);
void	def_index_minb(t_stack *stack_b, t_info *info);

void	fill_stack_b(t_stack *stack_a, t_stack *stack_b, t_info *info);

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