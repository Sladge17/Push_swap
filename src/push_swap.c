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
	
	info.filltop_b = 0;
	while (stack_a.top > 4)
	{
		def_median(&stack_a, &info);
		info.filltop_b += stack_a.top / 2;
		while (stack_b.top < info.filltop_b)
		{
			// if (stack_a.data[stack_a.top - 2] > stack_a.data[stack_a.top - 1]) //MAYBE OPTIMIZE WITH CHANGES
			// 	swap_a(&stack_a, &stack_b, &info);
			// if (stack_a.data[stack_a.top - 1] <= info.median &&
			// 	stack_a.data[stack_a.top - 2] <= info.median &&
			// 	stack_a.data[stack_a.top - 2] > stack_a.data[stack_a.top - 1])
			// 	swap_a(&stack_a, &stack_b, &info);
			if (stack_a.data[stack_a.top - 1] > info.median)
			{
				push_b(&stack_a, &stack_b, &info);
				if (stack_b.top == 1)
					continue ;


				while (!check_sort_b(&stack_b))
				{
					if (stack_b.top == 2)
					{
						sort_b_2memb(&stack_a, &stack_b, &info);
						break ;
					}

					if (stack_b.top == 3)
					{
						sort_b_3memb(&stack_a, &stack_b, &info);
						break ;
					}

					def_index_maxb(&stack_b, &info);
					if (info.ind_maxb == stack_b.top - 1)
					{
						if (stack_a.data[stack_a.top - 1] <= info.median)
						{
							//OPTIM UP A BETWEEN LESS MEDIAN
							if (stack_a.data[stack_a.top - 2] <= info.median &&
								stack_a.data[stack_a.top - 2] > stack_a.data[stack_a.top - 1])
								swap_a(&stack_a, &stack_b, &info);
							//END OPTIM
							rot_ab(&stack_a, &stack_b, &info);
						}
						else
							rot_b(&stack_a, &stack_b, &info);
						break ;
					}

					def_index_minb(&stack_b, &info);

					if (info.ind_minb[1] == stack_b.top - 1)
					{
						if (stack_a.data[stack_a.top - 2] > stack_a.data[stack_a.top - 1])
							swap_ab(&stack_a, &stack_b, &info);
						else
							swap_b(&stack_a, &stack_b, &info);
						break ;
					}

					if (stack_a.data[stack_a.top - 2] > stack_a.data[stack_a.top - 1])
						swap_ab(&stack_a, &stack_b, &info);
					else
						swap_b(&stack_a, &stack_b, &info);
					push_a(&stack_a, &stack_b, &info);
					continue ;
				}
				continue ;
			}
			rot_a(&stack_a, &stack_b, &info);
		}
	}
	if (stack_a.top == 4)
	{
		sort_a_4memb(&stack_a, &stack_b, &info);
	}
	if (stack_a.top == 3)
	{
		sort_a_3memb(&stack_a, &stack_b, &info);
	}
	if (stack_a.top == 2)
	{
		sort_a_2memb(&stack_a, &stack_b, &info);
	}
	depletion_b(&stack_a, &stack_b, &info);
}


char	check_sort_a(t_stack *stack_a)
{
	int		i;

	i = 0;
	while (i < stack_a->top - 1) // ?? top - 2
	{
		if (stack_a->data[i] > stack_a->data[i + 1])
			return (0);
		i += 1;
	}
	return (1);
}

char	check_sort_b(t_stack *stack_b)
{
	int		i;

	i = 0;
	while (i < stack_b->top - 1)
	{
		if (stack_b->data[i] < stack_b->data[i + 1])
			return (0);
		i += 1;
	}
	return (1);
}

void	depletion_b(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	while (stack_b->top)
		push_a(stack_a, stack_b, info);
}


void	def_median(t_stack *stack_a, t_info *info)
{
	int		tmp_arr[stack_a->top];
	char	sorted;
	int		i;
	int		tmp;

	i = 0;
	while (i < stack_a->top)
	{
		tmp_arr[i] = stack_a->data[i];
		i += 1;
	}
	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < stack_a->top - 1)
		{
			if (tmp_arr[i] > tmp_arr[i + 1])
			{
				tmp = tmp_arr[i];
				tmp_arr[i] = tmp_arr[i + 1];
				tmp_arr[i + 1] = tmp;
				sorted = 0;
			}
			i += 1;
		}
	}
	info->median = tmp_arr[(stack_a->top - 1) / 2];
}




void	def_index_maxb(t_stack *stack_b, t_info *info)
{
	int		i;
	
	info->ind_maxb = 0;
	i = 1;
	while (i < stack_b->top)
	{
		if (stack_b->data[i] > stack_b->data[info->ind_maxb])
			info->ind_maxb = i;
		i += 1;
	}
}


void	def_index_mina(t_stack *stack_a, t_info *info)
{
	int		i;
	
	info->ind_mina = 0;
	i = 1;
	while (i < stack_a->top)
	{
		if (stack_a->data[i] < stack_a->data[info->ind_mina])
			info->ind_mina = i;
		i += 1;
	}
}

void	def_index_maxa(t_stack *stack_a, t_info *info)
{
	int		i;
	
	info->ind_maxa = 0;
	i = 1;
	while (i < stack_a->top)
	{
		if (stack_a->data[i] > stack_a->data[info->ind_maxa])
			info->ind_maxa = i;
		i += 1;
	}
}



void	def_index_minb(t_stack *stack_b, t_info *info)
{
	int		i;
	
	if (stack_b->data[0] < stack_b->data[1])
	{
		info->ind_minb[0] = 0;
		info->ind_minb[1] = 1;
	}
	else
	{
		info->ind_minb[0] = 1;
		info->ind_minb[1] = 0;
	}
	
	
	// info->ind_minb[0] = 0;
	i = 2;
	while (i < stack_b->top)
	{
		if (stack_b->data[i] < stack_b->data[info->ind_minb[0]])
		{
			info->ind_minb[1] = info->ind_minb[0];
			info->ind_minb[0] = i;
			i += 1;
			continue ;
		}
		if (stack_b->data[i] < stack_b->data[info->ind_minb[1]])
		{
			info->ind_minb[1] = i;
			i += 1;
			continue ;
		}
		i += 1;
	}
	printf("%d %d\n", info->ind_minb[0], info->ind_minb[1]);
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
