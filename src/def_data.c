/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:31:44 by marvin            #+#    #+#             */
/*   Updated: 2020/04/23 16:31:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	def_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int		i;
	
	if (!(stack_a->data = (int *)malloc(sizeof(int) * (argc - 1))))
		exit(0);
	if (!(stack_b->data = (int *)malloc(sizeof(int) * (argc - 1))))
		exit(0);
	i = 0;
	while (i < argc - 1)
	{
		stack_a->data[i] = atoi(argv[i + 1]);
		i += 1;
	}
	stack_a->top = i;
	stack_b->top = 0;
}

void	def_info(t_info *info, int argc)
{
	info->argc = argc - 2;
	info->count = 0;
	// info->noparall = 0;
}
