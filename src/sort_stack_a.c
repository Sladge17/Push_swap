/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:57:56 by marvin            #+#    #+#             */
/*   Updated: 2020/04/23 16:57:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_1memb(t_stack *stack_a)
{
	if (stack_a->top == 1)
		exit(0);
}

void	sort_a_2memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	if (stack_a->data[stack_a->top - 2] < stack_a->data[stack_a->top - 1])
		return ;
	swap_a(stack_a, stack_b, info);
}

void	sort_a_3memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	def_index_mina(stack_a, info);
	if (info->ind_mina == 1)
		rotr_a(stack_a, stack_b, info);
	if (info->ind_mina == 2)
		rot_a(stack_a, stack_b, info);
	sort_a_2memb(stack_a, stack_b, info);
}

void	sort_a_4memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		i;
	char	sorted;

	sorted = 1;
	i = 0;
	while (i < 3)
	{
		if (stack_a->data[i] > stack_a->data[i + 1])
		{
			sorted = 0;
			break ;
		}
		i += 1;
	}
	if (sorted)
		return ;

	def_index_maxa(stack_a, info);
	if (info->ind_maxa == 0)
	{
		rotr_a(stack_a, stack_b, info);
		info->ind_maxa = 3;
	}
	while (info->ind_maxa != 3)
	{
		rot_a(stack_a, stack_b, info);
		info->ind_maxa += 1;
	}
	push_b(stack_a, stack_b, info);
	sort_a_3memb(stack_a, stack_b, info);
	push_a(stack_a, stack_b, info);
}

// void	sort_a_5memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
// {
// 	int		i;
// 	char	sorted;

// 	sorted = 1;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (stack_a->data[i] > stack_a->data[i + 1])
// 		{
// 			sorted = 0;
// 			break ;
// 		}
// 		i += 1;
// 	}
// 	if (sorted)
// 		return ;
	
// 	def_index_maxa(stack_a, info);
// 	if (info->ind_maxa == 0)
// 	{
// 		rotr_a(stack_a, stack_b, info);
// 		info->ind_maxa = 4;
// 	}
// 	if (info->ind_maxa == 1)
// 	{
// 		rotr_a(stack_a, stack_b, info);
// 		rotr_a(stack_a, stack_b, info);
// 		info->ind_maxa = 4;
// 	}
// 	while (info->ind_maxa != 4)
// 	{
// 		rot_a(stack_a, stack_b, info);
// 		info->ind_maxa += 1;
// 	}
// 	push_b(stack_a, stack_b, info);
// 	sort_a_4memb(stack_a, stack_b, info);
// 	push_a(stack_a, stack_b, info);
// }