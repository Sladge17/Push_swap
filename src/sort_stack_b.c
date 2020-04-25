/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:56:47 by marvin            #+#    #+#             */
/*   Updated: 2020/04/24 13:56:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_2memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	// if (stack_b->data[0] > stack_b->data[1])
	// 	return ;
	if (stack_a->data[stack_a->top - 2] > stack_a->data[stack_a->top - 1])
		swap_ab(stack_a, stack_b, info);
	else
	{
		if (stack_a->data[stack_a->top - 1] <= info->median)
			rot_ab(stack_a, stack_b, info);
		else
			swap_b(stack_a, stack_b, info); //may change to rot_b rotr_b
	}
}

// void	sort_b_2memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
// {
// 	// if (stack_b->data[0] > stack_b->data[1])
// 	// 	return ;
// 	if (stack_a->data[stack_a->top - 1] <= info->median)
// 			rot_ab(stack_a, stack_b, info);
// 	else
// 	{
// 		if (stack_a->data[stack_a->top - 2] > stack_a->data[stack_a->top - 1])
// 			swap_ab(stack_a, stack_b, info);
// 		else
// 			swap_b(stack_a, stack_b, info); //may change to rot_b rotr_b
// 	}
// }

void	sort_b_3memb(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	def_index_maxb(stack_b, info);
	if (info->ind_maxb == stack_b->top - 1)
	{
		if (stack_a->data[stack_a->top - 1] <= info->median)
		{
			// //OPTIM UP A BETWEEN LESS MEDIAN
			// if (stack_a->data[stack_a->top - 2] <= info->median &&
			// 	stack_a->data[stack_a->top - 2] > stack_a->data[stack_a->top - 1])
			// 	swap_a(stack_a, stack_b, info);
			// //END OPTIM
			rot_ab(stack_a, stack_b, info);
		}
		else
			rot_b(stack_a, stack_b, info);
		return ;
	}
	if (stack_a->data[stack_a->top - 2] > stack_a->data[stack_a->top - 1])
		swap_ab(stack_a, stack_b, info);
	else
		swap_b(stack_a, stack_b, info);
}
