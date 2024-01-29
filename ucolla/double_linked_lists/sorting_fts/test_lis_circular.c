/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lis_circular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:16:58 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/29 16:30:06 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

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
	return (ret);
}

void	ft_circular_lis(t_lis **stack_lis)
{
	t_lis	*tmp;
	t_lis	*i;
	t_lis	*j;
	int		head;
	
	tmp = *stack_lis;
	i = *stack_lis;
	i = i->next;
	j = *stack_lis;
	head = tmp->index;
	ft_last_lis(tmp)->next = tmp;
	while (i->index != head)
	{
		j = *stack_lis;
		while (j->index != i->index)
		{
			if (j->index < i->index)
			{
				if (j->length == i->length)
					i->length = j->length + 1;
			}
			j = j->next;
		}
		i = i->next;
	}
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

	k = ft_list_size(stack);
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