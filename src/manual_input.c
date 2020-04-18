/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:08:24 by marvin            #+#    #+#             */
/*   Updated: 2020/04/17 11:08:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manual_input(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	char		input[3];
	
	while (1)
	{
		scanf("%s", input);
		if (!strcmp(input, "0"))
			break ;
		if (!strcmp(input, "sa"))
		{
			swap_a(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "sb"))
		{
			swap_b(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "ss"))
		{
			swap_ab(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "pa"))
		{
			push_a(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "pb"))
		{
			push_b(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "pb"))
		{
			push_b(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "ra"))
		{
			rot_a(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "rb"))
		{
			rot_b(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "rr"))
		{
			rot_ab(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "rra"))
		{
			rotr_a(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "rrb"))
		{
			rotr_b(stack_a, stack_b, info);
			continue ;
		}
		if (!strcmp(input, "rrr"))
		{
			rotr_ab(stack_a, stack_b, info);
			continue ;
		}
		printf("Unknown command\n");
	}
}