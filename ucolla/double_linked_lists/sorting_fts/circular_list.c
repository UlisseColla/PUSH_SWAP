/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:18:02 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/29 16:15:04 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

t_lis	*ft_find_in_lis(t_lis **lis, int index, int size)
{
	t_lis	*tmp;
	int		i;

	tmp = *lis;
	i = 0;
	while (i < size)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

t_lis	*ft_node_lis(int index)
{
	t_lis	*new;

	new = (t_lis *)malloc(sizeof(t_lis));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->lis_index = 0;
	new->length = 1;
	new->next = NULL;
	return (new);
}

void	ft_addback_lis(t_lis **list, t_lis *new)
{
	t_lis	*tmp;

	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

t_lis	*index_lis_init(t_stack **stack, int size_stack)
{
	int		i;
	t_lis	*lis;
	t_lis	*new;

	i = 0;
	lis = NULL;
	while (i < size_stack)
	{
		new = ft_node_lis(0);
		new->index = (*stack)->index;
		new->lis_index = i;
		ft_addback_lis(&lis, new);
		i++;
		*stack = (*stack)->next;
	}
	return (lis);
}

t_lis	*ft_last_lis(t_lis *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
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

int	find_biggest_length(t_lis *lis, int size)
{
	int		max_value;
	int		current_value;
	int		i;
	t_lis	*tmp;

	max_value = 0;
	tmp = lis;
	i = 0;
	while (i < size)
	{
		current_value = tmp->length;
		if (current_value > max_value)
		{
			max_value = current_value;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp->length > max_value)
		max_value = tmp->length;
	return (max_value);
}
/*
//trova differenza tra elemento dove sono e il prossimo con legnth + 1
int	find_difference(t_lis **lis, int tail, int length)
{
	t_lis	*tmp;

	tmp = *lis;
	while (tmp->index != tail)
	{
		// printf("diff: %d\n", tmp->index);
		if (tmp->length == length + 1)
			return (tmp->index - (*lis)->index);
		tmp = tmp->next;
	}
	return (0);
}

int	check_path_length(t_lis **lis, int length, int biggest_length, int tail)
{
	t_lis	*tmp;
	t_lis	*tmp2;

	tmp = *lis;
	tmp2 = *lis;
	while (tmp2->index != tail)
	{
		printf("ok\n");
		if (tmp2->length == length && tmp2->index > tmp->index)
			length++;
		tmp2 = tmp2->next;
	}
	if (length == biggest_length)
		return (1);
	return (0);
}

int	*find_best_lis(t_lis **lis, int diff, int tail, int size)
{
	t_lis	*tmp;
	t_lis	*best_match;
	int		*lis_arr;
	int		length;
	int		prev_index;
	int		biggest_length;

	tmp = *lis;
	best_match = *lis;
	prev_index = 0;
	biggest_length = find_biggest_length(*lis, size);
	lis_arr = (int *)malloc(sizeof(int) * biggest_length + 1);
	lis_arr[biggest_length] = -1;
	length = 1;
	while (tmp->index != tail)
	{
		if (tmp->length == length)
		{
			best_match = tmp;
			
			if (length > 1)
				diff = tmp->index - lis_arr[length - 2];
			else
				diff = 1;
			
			lis_arr[length - 1] = tmp->index;
			printf("\n1. lis_arr: %d", lis_arr[length - 1]);
			while (best_match->index != tail && diff > 1)
			{
				prev_index = lis_arr[length - 2];
				if ((best_match->index - lis_arr[length - 2]) < diff && best_match->length == length &&
					best_match->index > lis_arr[length - 2] &&
					best_match->lis_index > ft_find_in_lis(&tmp, prev_index, size)->lis_index)
				{
					// printf("\nbest_match->index: %d -- lis_arr[length - 2]: %d\n", best_match->index, lis_arr[length - 2]);
					if (check_path_length(&best_match, length, biggest_length, tail) == 1)
					{
						lis_arr[length - 1] = best_match->index;
						printf(" -- 2. lis_arr: %d\n", lis_arr[length - 1]);
						diff = best_match->index - lis_arr[length - 2];
					}
				}
				best_match = best_match->next;
			}
			length++;
		}
		tmp = tmp->next;
	}
	if (tmp->length == length && tmp->index > lis_arr[length - 2])
		lis_arr[length - 1] = tmp->index;
	return (lis_arr);
} */
