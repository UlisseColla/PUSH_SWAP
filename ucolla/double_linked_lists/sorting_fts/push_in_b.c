/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:21:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/18 18:33:51 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* 
	1. Pusho i primi due numeri in B
	2. Calcolo di volta in volta chi mi conviene pushar in B e poi lo pusho
 */

/* comincio il calcolo con l'array di arrivo gia' in ordine decrescente */
// long	calculate_cost_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	long	moves;

// 	moves = 0;
// 	if (((*stack_a)->value > (*stack_b)->value && (*stack_a)->value > ft_list_last((*stack_b))->value)
// 		|| ((*stack_a)->value > (*stack_b)->value && (*stack_a)->value < ft_list_last((*stack_b))->value))
// 		return (1); //Potrei pushare in B
// 	else if ((*stack_a)->value < (*stack_b)->value && (*stack_a)->value > ft_list_last((*stack_b))->value)
// 	{
// 		while ((*stack_a)->value < (*stack_b)->value && (*stack_a)->value < ft_list_last((*stack_b))->value)
// 		{
// 			rotate_b(stack_b); //ruoto A fino a che B non si trova nell'ordine giusto da poter pushare
// 			moves++;
// 		}
// 	}
// 	return (moves);
// }

/* cicla in stack finche' non trovi l'indice precedente o successivo;
	Parametri:
	- stack su cui fare ricerca
	- index del nodo che voglio spostare
	-! possibile parametro long i che passa il numero di rotate di cui avrei bisogno
	  per spostare in cima alla lista il numero di cui sto calcolando il costo
 */
 
long	calculate_cost_top(t_stack **stack, long index, long n_rotate)
{
	long	i;
	long	j;
	t_stack	*tmp;

	i = ft_list_size(*stack);
	j = 0;
	tmp = *stack;
	while (j < i && tmp)
	{
		if (tmp->index > index || index > (ft_list_find_node(*stack ,find_biggest(stack)))->index)
			break ;
		tmp = tmp->next;
		j++;
	}
	// printf("calculate j: %ld -- i: %ld\n", j, n_rotate);
	return (j + n_rotate + 1);
}

long	calculate_cost_bottom(t_stack **stack, long index, long n_r_rotate)
{
	long	i;
	long	j;
	t_stack	*tmp;

	i = ft_list_size(*stack);
	j = 1;
	tmp = *stack;
	if (index > (ft_list_find_node(*stack ,find_biggest(stack)))->index)
		return (n_r_rotate + 2);
	while (j < i && tmp)
	{
		if (tmp->index > index)
			break ;
		tmp = tmp->prev;
		j++;
	}
	return (j + n_r_rotate + 1);
}

void	push_in_b(t_stack **a, t_stack **b)
{
	long	i;

	i = ft_list_size(*a);
	while (i > 0)
	{
		if ((*a)->push == true)
			push_b(b, a);
		else
			rotate_a(a);
		i--;
	}
}

void	push_in_a(t_stack **a, t_stack **b)
{
	long	i;
	long	j;
	t_stack	*tmp;

	i = ft_list_size(*b) / 2;
	j = 0;
	(void)a;
	tmp = *b;
	printf("size_B: %ld\n", i);
	while (j < i)
	{
		// printf("<<< Costo: %ld -- index: %d >>>\n\n", calculate_cost_top(a, tmp->index, j), tmp->index);
		tmp = tmp->next;
		j++;
	}
	j = 0;
	tmp = ft_list_last(*b);
	while (j < i)
	{
		printf("<<< Costo: %ld -- index: %d >>>\n\n", calculate_cost_bottom(a, tmp->index, j), tmp->index);
		tmp = tmp->prev;
		j++;
	}
}

// while ((*b)->index > (*a)->index)
// {
// 	rotate_a(a);
// 	if ()
// }