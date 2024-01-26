/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:34:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/26 19:27:51 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

static void	init_one(int *array, int size)
{
	int	j;

	j = -1;
	while (++j < size)
		array[j] = 1;
}

int	arr_biggest(int *array, int size)
{
	int		max_value;
	int		current_value;
	int		i;

	max_value = INT_MIN;
	i = 0;
	while (i < size)
	{
		current_value = array[i];
		if (current_value > max_value)
			max_value = current_value;
		i++;
	}
	return (max_value);
}

int	ft_index(int *args, int num)
{
	int	i;

	i = 0;
	while (args[i] && args[i] != num)
		i++;
	return (i);
}

int	*build_array(int *length, int *array, int *sub_sequence, int size)
{
	int	biggest_length;
	int	*ret;
	int	p;
	int	u;

	biggest_length = arr_biggest(length, size);
	ret = (int *)malloc(sizeof(int) * (biggest_length + 1));
	p = biggest_length;
	u = sub_sequence[ft_index(length, biggest_length)];
	ret[p] = -1;
	p--;
	ret[p] = array[ft_index(length, biggest_length)];
	p--;
	while (p >= 0)
	{
		ret[p] = array[u];
		u = sub_sequence[u];
		p--;
	}
	//free length e sub_sequence
	return (ret);
}

int	*ft_lis(int *array, int size, int i, int j)
{
	int	*sub_sequence;
	int	*length;

	length = (int *)malloc(sizeof(int) * size);
	sub_sequence = (int *)malloc(sizeof(int) * size);
	init_one(length, size);
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i])
			{
				if (length[j] == length[i])
				{
					length[i] = length[j] + 1;
					sub_sequence[i] = ft_index(array, array[j]);
				}
			}
			j++;
		}
		i++;
	}
	return (build_array(length, array, sub_sequence, size));
}

void ft_list_lis(t_stack **stack, int size)
{
	int		*tmp;
	int		tmp_tail;
	int		k;
	int		j;
	t_stack *stack_tmp;
	t_stack	*substack_head;
	t_stack	*substack_tail;


	k = ft_list_size(*stack);
	j = 0;
	tmp = ft_lis(create_array(*stack, size), size, 1, 0);
	stack_tmp = *stack;
	stack_tmp->prev = ft_list_last(stack_tmp);
	ft_list_last(stack_tmp)->next = stack_tmp;
	tmp_tail = ft_list_find_index(*stack, tmp[0])->prev->index;
	substack_tail = ft_list_find_index(*stack, tmp[0]);
	while (tmp[j] != -1)
	{
		printf("LIS: %d\n", tmp[j]);
		j++;
	}
	j--;
	substack_head = ft_list_find_index(*stack, tmp[j])->next;
	
	// printf("tmp_head: %d\n", tmp_head);
	// printf("tmp_tail: %d\n", tmp_tail);
	
	j = 0;
	while (substack_tail->index != substack_head->index)
	{
		substack_tail = substack_tail->next;
		j++;
	}
	
	int a = k - j;
	int *tmp_arr = create_sub_array(substack_head, tmp_tail);
	int	*tmp_LIS = ft_lis(tmp_arr, a, 1, 0);
	while (*tmp_LIS != -1)
	{
		printf("SUB_LIS: %d\n", *tmp_LIS);
		tmp_LIS++;
	}
	printf("\n\n");
}

// void find_best_lis(t_stack **stack, int size)
// {
// 	t_stack *stack_tmp;
	
// 	stack_tmp = *stack;
// 	while (stack_tmp)
// 	{
// 		ft_list_lis(stack, size);
// 		stack_tmp = stack_tmp->next;
// 	}
// }
