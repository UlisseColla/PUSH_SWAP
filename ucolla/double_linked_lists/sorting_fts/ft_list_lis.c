/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:18:02 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/26 19:36:13 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

t_lis	*ft_node_lis(int index)
{
	t_lis	*new;

	new = (t_lis *)malloc(sizeof(t_lis));
	if (new == NULL)
		return (NULL);
	new->index = index;
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

int	find_biggest_length(t_lis *lis, int tail)
{
	int		max_value;
	int		current_value;
	int		i;
	t_lis	*tmp;

	max_value = 0;
	tmp = lis;
	i = 0;
	while (i < tail)
	{
		current_value = tmp->length;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
		i++;
	}
	if (tmp->length > max_value)
		max_value = tmp->length;
	return (max_value);
}

int	find_difference(t_lis **lis, int tail, int length)
{
	t_lis	*tmp;

	tmp = *lis;
	while (tmp->index != tail)
	{
		if (tmp->length == length + 1)
			return (tmp->index);
	}
	return (0);
}

int	*find_best_lis(t_lis **lis, int i, int tail)
{
	t_lis	*tmp;
	t_lis	*best_match;
	int		*lis_arr;
	int		length;

	tmp = *lis;
	best_match = *lis;
	lis_arr = (int *)malloc(sizeof(int) * find_biggest_length(*lis, tail) + 1);
	lis_arr[find_biggest_length(*lis, tail)] = -1;
	length = 1;
	while (tmp->index != tail)
	{
		printf("tmp->index: %d\n", tmp->index);
		if (tmp->length == length)
		{
			best_match = *lis;
			i = find_difference(lis, tail, length);
			lis_arr[length - 1] = tmp->index;
			printf("lis_arr: %d\n", lis_arr[length - 1]);
			while (best_match->index != tail && i > 1)
			{
				if (best_match->length == tmp->length && (best_match->index - tmp->index) < i)
				{
					lis_arr[length - 1] = best_match->index;
					i = best_match->index - tmp->index;
				}
			}
		}
		tmp = tmp->next;
	}
	return (lis_arr);
}
