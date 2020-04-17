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

void	manual_input(int argc, t_stack *stack_a, t_stack *stack_b, int *count)
{
	char		input[3];
	
	while (1)
	{
		scanf("%s", input);
		if (!strcmp(input, "0"))
			break ;
		if (!strcmp(input, "sa"))
		{
			swap_a(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "sb"))
		{
			swap_b(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "ss"))
		{
			swap_ab(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "pa"))
		{
			push_a(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "pb"))
		{
			push_b(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "pb"))
		{
			push_b(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "ra"))
		{
			rot_a(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "rb"))
		{
			rot_b(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "rr"))
		{
			rot_ab(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "rra"))
		{
			rotr_a(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "rrb"))
		{
			rotr_b(argc, stack_a, stack_b, count);
			continue ;
		}
		if (!strcmp(input, "rrr"))
		{
			rotr_ab(argc, stack_a, stack_b, count);
			continue ;
		}
		printf("Unknown command\n");
	}
}