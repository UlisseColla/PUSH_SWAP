/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:18:02 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/30 15:41:07 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* assegna lis_index a tutta la lista lis */
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
		new->sub_sequence = 0;
		ft_addback_lis(&lis, new);
		i++;
		*stack = (*stack)->next;
	}
	return (lis);
}

/* resetta valori a tutta la lista lis */
void	refresh_lis(t_lis **lis, int stack_size)
{
	int i;

	i = 0;
	while (i < stack_size)
	{
		(*lis)->length = 1;
		(*lis)->lis_index = i;
		(*lis)->sub_sequence = 0;
		i++;
		*lis = (*lis)->next;
	}
}

/* trova i valori length per la lis nella lista circolare */
int	*ft_circular_lis(t_lis **stack_lis, int stack_size)
{
	t_lis	*i;
	t_lis	*j;
	int		head;
	
	i = *stack_lis->next;
	j = *stack_lis;
	head = (*stack_lis)->index;
	ft_last_lis(*stack_lis)->next = *stack_lis;
	refresh_lis(stack_lis, stack_size);
	while (i->index != head)
	{
		j = *stack_lis;
		while (j->index != i->index)
		{
			if (j->index < i->index)
			{
				if (j->length == i->length)
				{
					i->length = j->length + 1;
					i->sub_sequence = j->lis_index;
				}
			}
			j = j->next;
		}
		i = i->next;
	}
	return (build_lis(stack_lis, stack_size));
}

/* costruisci la sequenza vera e propria */
int	*build_lis(t_lis **lis, int size)
{
	int	*ret;
	int	biggest_length;
	int	p;
	int	u;

	biggest_length = find_biggest_length(*lis, size);
	ret = (int *)malloc(sizeof(int) * (biggest_length + 1));
	p = biggest_length;
	u = find_biggest_length_node(*lis, size, biggest_length)->sub_sequence;
	ret[p] = -1;
	p--;
	ret[p] = find_biggest_length_node(*lis, size, biggest_length)->index;
	// printf("ret[%d]: %d\n", p, ret[p]);
	p--;
	while (p >= 0)
	{
		ret[p] = ft_find_lis_index(lis, u, size)->index;
		// printf("ret[%d]: %d\n", p, ret[p]);
		u = ft_find_lis_index(lis, u, size)->sub_sequence;
		p--;
	}
	return (ret);
}
