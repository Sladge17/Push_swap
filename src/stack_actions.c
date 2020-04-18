/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 10:39:57 by marvin            #+#    #+#             */
/*   Updated: 2020/04/17 10:39:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;

	if (stack_a->top < 2)
		return ;
	tmp = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = stack_a->data[stack_a->top - 2];
	stack_a->data[stack_a->top - 2] = tmp;
	info->count += 1;
	info->action = "swap_a";
	put_stacks(stack_a, stack_b, info);
}

void	swap_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;

	if (stack_b->top < 2)
		return ;
	tmp = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = stack_b->data[stack_b->top - 2];
	stack_b->data[stack_b->top - 2] = tmp;
	info->count += 1;
	info->action = "swap_b";
	put_stacks(stack_a, stack_b, info);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	char	flag;

	flag = 0;
	if (stack_a->top > 1)
	{
		tmp = stack_a->data[stack_a->top - 1];
		stack_a->data[stack_a->top - 1] = stack_a->data[stack_a->top - 2];
		stack_a->data[stack_a->top - 2] = tmp;
		flag = 1;
	}
	if (stack_b->top > 1)
	{
		tmp = stack_b->data[stack_b->top - 1];
		stack_b->data[stack_b->top - 1] = stack_b->data[stack_b->top - 2];
		stack_b->data[stack_b->top - 2] = tmp;
		flag = 1;
	}
	if (flag)
	{
		info->count += 1;
		info->action = "swap_ab";
		put_stacks(stack_a, stack_b, info);
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	if (!stack_b->top)
		return ;
	stack_a->data[stack_a->top] = stack_b->data[stack_b->top - 1];
	stack_a->top += 1;
	stack_b->top -= 1;
	info->count += 1;
	info->action = "push_a";
	put_stacks(stack_a, stack_b, info);
}

void	push_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	if (!stack_a->top)
		return ;
	stack_b->data[stack_b->top] = stack_a->data[stack_a->top - 1];
	stack_b->top += 1;
	stack_a->top -= 1;
	info->count += 1;
	info->action = "push_b";
	put_stacks(stack_a, stack_b, info);
}

void	rot_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;
	
	if (stack_a->top < 2)
		return ;
	tmp = stack_a->data[stack_a->top - 1];
	i = stack_a->top - 1;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i -= 1;
	}
	stack_a->data[0] = tmp;
	info->count += 1;
	info->action = "rotate_a";
	put_stacks(stack_a, stack_b, info);
}

void	rot_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;
	
	if (stack_b->top < 2)
		return ;
	tmp = stack_b->data[stack_b->top - 1];
	i = stack_b->top - 1;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i -= 1;
	}
	stack_b->data[0] = tmp;
	info->count += 1;
	info->action = "rotate_b";
	put_stacks(stack_a, stack_b, info);
}

void	rot_ab(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;
	char	flag;
	
	flag = 0;
	if (stack_a->top > 1)
	{
		tmp = stack_a->data[stack_a->top - 1];
		i = stack_a->top - 1;
		while (i > 0)
		{
			stack_a->data[i] = stack_a->data[i - 1];
			i -= 1;
		}
		stack_a->data[0] = tmp;
		flag = 1;
	}
	if (stack_b->top > 1)
	{
		tmp = stack_b->data[stack_b->top - 1];
		i = stack_b->top - 1;
		while (i > 0)
		{
			stack_b->data[i] = stack_b->data[i - 1];
			i -= 1;
		}
		stack_b->data[0] = tmp;
		flag = 1;
	}
	if (flag)
	{
	info->count += 1;
	info->action = "rotate_ab";
	put_stacks(stack_a, stack_b, info);
	}
}

void	rotr_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;

	int		tmp2 = stack_b->top;
	tmp2 = tmp2 + 1;
	
	if (stack_a->top < 2)
		return ;
	tmp = stack_a->data[0];
	i = 0;
	while (i < stack_a->top - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i += 1;
	}
	stack_a->data[stack_a->top - 1] = tmp;
	info->count += 1;
	info->action = "rotateR_a";
	put_stacks(stack_a, stack_b, info);
}

void	rotr_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;
	
	if (stack_b->top < 2)
		return ;
	tmp = stack_b->data[0];
	i = 0;
	while (i < stack_b->top - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i += 1;
	}
	stack_b->data[stack_b->top - 1] = tmp;
	info->count += 1;
	info->action = "rotateR_b";
	put_stacks(stack_a, stack_b, info);
}

void	rotr_ab(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		tmp;
	int		i;
	char	flag;
	
	flag = 0;
	if (stack_a->top > 1)
	{
		tmp = stack_a->data[0];
		i = 0;
		while (i < stack_a->top - 1)
		{
			stack_a->data[i] = stack_a->data[i + 1];
			i += 1;
		}
		stack_a->data[stack_a->top - 1] = tmp;
		flag = 1;
	}
	if (stack_b->top > 1)
	{
		tmp = stack_b->data[0];
		i = 0;
		while (i < stack_b->top - 1)
		{
			stack_b->data[i] = stack_b->data[i + 1];
			i += 1;
		}
		stack_b->data[stack_b->top - 1] = tmp;
		flag = 1;
	}
	if (flag)
	{
		info->count += 1;
		info->action = "rotateR_ab";
		put_stacks(stack_a, stack_b, info);
	}
}