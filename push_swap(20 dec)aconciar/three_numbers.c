/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:44:10 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 17:10:45 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_numbers(t_list **stack_a, t_list **stack_b)
{
	int	moves;

	moves = 0;
	if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) < (*(int *)ft_lstlast(*stack_a)->content)))
	{
		swap(stack_a);
		moves++;
	}
	else if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->next->content) > (*(int *)ft_lstlast(*stack_a)->content)))
	{
		swap(stack_a);
		reverse_rotate(stack_a);
		moves += 2;
	}
	else if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->next->content) < (*(int *)ft_lstlast(*stack_a)->content)))
	{
		rotate (stack_a);
		moves++;
	}
	else if (((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) < (*(int *)ft_lstlast(*stack_a)->content)))
	{
		swap(stack_a);
		rotate(stack_a);
		moves += 2;
	}
	else if (((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) > (*(int *)ft_lstlast(*stack_a)->content)))
	{
		reverse_rotate(stack_a);
		moves++;
	}
	return (moves);
}
