/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:15:55 by marvin            #+#    #+#             */
/*   Updated: 2020/04/13 17:15:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_info		info;

	if (argc == 1)
	{
		printf("Need input arguments for stacks\n");
		return (0);
	}


	def_stacks(&stack_a, &stack_b, argc, argv);
	def_info(&info, argc);
	put_stacks(&stack_a, &stack_b, &info);

	// manual_input(&stack_a, &stack_b, &info);

	if (stack_a.top < 4)
	{
		sortup_a(&stack_a, &stack_b, &info);
		return (0);
	}
	def_threemin(&stack_a, &info);

	// while (stack_a.top != 3)
	// {
	// 	fill_stack_b(&stack_a, &stack_b, &info);
	// }
	// sortup_a(&stack_a, &stack_b, &info);
	// while (stack_b.top)
	// {
	// 	push_a(&stack_a, &stack_b, &info);
	// }

	while (stack_a.top != 3)
	{
		if (stack_a.data[stack_a.top - 1] != info.threemin[0] &&
			stack_a.data[stack_a.top - 1] != info.threemin[1] &&
			stack_a.data[stack_a.top - 1] != info.threemin[2])
		{
			push_b(&stack_a, &stack_b, &info);

			if (stack_b.top == 1)
				continue ;
			if (stack_b.top == 2)
			{
				if (stack_b.data[0] < stack_b.data[1])
				{
					swap_b(&stack_a, &stack_b, &info); // rot_b rotr_b
					continue ;
				}
				continue ;
			}
			if (stack_b.top == 3)
			{
				def_maxb(&stack_b, &info);
				if (info.ind_maxb == stack_b.top - 1)
				{
					rot_b(&stack_a, &stack_b, &info);
					continue ;
				}
				if (stack_b.data[1] < stack_b.data[2])
				{
					swap_b(&stack_a, &stack_b, &info);
					continue ;
				}
			}
			if (stack_b.top > 3)
			{
				def_maxb(&stack_b, &info);
				// if (info.ind_maxb == stack_b.top - 1)
				// {
				// 	rot_b(&stack_a, &stack_b, &info);
				// 	continue ;
				// }

				// rotr_b(&stack_a, &stack_b, &info);
				// push_a(&stack_a, &stack_b, &info);
				while (info.ind_maxb != stack_b.top - 1)
				{
					rotr_b(&stack_a, &stack_b, &info);
					push_a(&stack_a, &stack_b, &info);
					def_maxb(&stack_b, &info);
				}
				rot_b(&stack_a, &stack_b, &info);
				continue ;
			}
		}
		rot_a(&stack_a, &stack_b, &info);
	}
	return (0);
}

void	def_maxb(t_stack *stack_b, t_info *info)
{
	int		i;
	
	info->ind_maxb = 0;
	info->val_maxb = stack_b->data[0];
	i = 1;
	while (i < stack_b->top)
	{
		if (info->val_maxb < stack_b->data[i])
		{
			info->ind_maxb = i;
			info->val_maxb = stack_b->data[i];
		}
		i += 1;
	}
}

void	def_threemin(t_stack *stack_a, t_info *info)
{
	int		i;
	
	info->threemin[0] = stack_a->data[0];
	i = 1;
	while (i < 3)
	{
		if (stack_a->data[i] < info->threemin[0])
		{
			info->threemin[2] = info->threemin[1];
			info->threemin[1] = info->threemin[0];
			info->threemin[0] = stack_a->data[i];
			i += 1;
			continue ;
		}
		if (stack_a->data[i] < info->threemin[1])
		{
			info->threemin[2] = info->threemin[1];
			info->threemin[1] = stack_a->data[i];
			i += 1;
			continue ;
		}
		info->threemin[i] = stack_a->data[i];
		i += 1;
	}
	
	i = 3;
	while (i < stack_a->top)
	{
		if (stack_a->data[i] < info->threemin[0])
		{
			info->threemin[2] = info->threemin[1];
			info->threemin[1] = info->threemin[0];
			info->threemin[0] = stack_a->data[i];
			i += 1;
			continue ;
		}
		if (stack_a->data[i] < info->threemin[1])
		{
			info->threemin[2] = info->threemin[1];
			info->threemin[1] = stack_a->data[i];
			i += 1;
			continue ;
		}
		if (stack_a->data[i] < info->threemin[2])
		{
			info->threemin[2] = stack_a->data[i];
			i += 1;
			continue ;
		}
		i += 1;
	}
}

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
}


void	fill_stack_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		i;
	int		max_val;
	int		max_ind;

	max_val = stack_a->data[0];
	max_ind = 0;
	i = 1;
	while (i < stack_a->top)
	{
		if (max_val < stack_a->data[i])
		{
			max_val = stack_a->data[i];
			max_ind = i;
		}
		i += 1;
	}
	if (max_ind == stack_a->top - 1)
	{
		push_b(stack_a, stack_b, info);
		return ;
	}
	if (max_ind == 0)
	{
		rotr_a(stack_a, stack_b, info);
		push_b(stack_a, stack_b, info);
		return ;
	}

	if (max_ind + 1 < stack_a->top - 1 - max_ind)
	{
		while (max_ind)
		{
			rotr_a(stack_a, stack_b, info);
			max_ind -= 1;
		}
		rotr_a(stack_a, stack_b, info);
		push_b(stack_a, stack_b, info);
		return ;
	}


	while (max_ind != stack_a->top - 1)
	{
		rot_a(stack_a, stack_b, info);
		max_ind += 1;
	}
	push_b(stack_a, stack_b, info);
}

void	sortup_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		i;
	int		min_val;
	int		min_ind;

	min_val = stack_a->data[0];
	min_ind = 0;
	i = 1;
	while (i < stack_a->top)
	{
		if (min_val > stack_a->data[i])
		{
			min_val = stack_a->data[i];
			min_ind = i;
		}
		i += 1;
	}
	if (min_ind == stack_a->top - 1)
		rot_a(stack_a, stack_b, info);
	else
		while (min_ind)
		{
			rotr_a(stack_a, stack_b, info);
			min_ind -= 1;
		}
	if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top - 2])
		swap_a(stack_a, stack_b, info);
}

void	put_stacks(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	static int	first = 0;
	int			i;

	printf("\n");
	if (first)
		printf("action: %s\n", info->action);
	first |= 1;
	printf("index	stack_a	stack_b\n");
	i = info->argc;
	while (i >= 0)
	{
		printf("  %d	", i);
		if (i < stack_a->top)
			printf("  %d	", stack_a->data[i]);
		else
			printf("  -	");

		if (i < stack_b->top)
			printf("  %d\n", stack_b->data[i]);
		else
			printf("  -\n");
		i -= 1;
	}
	printf("count = %d\n", info->count);
}
