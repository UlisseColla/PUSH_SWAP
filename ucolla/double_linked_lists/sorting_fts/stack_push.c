/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:21:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/22 19:04:42 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* cicla in stack finche' non trovi l'indice precedente o successivo;
	Parametri:
	- stack su cui fare ricerca
	- index del nodo che voglio spostare
	-! possibile parametro long i che passa il numero di rotate di cui avrei bisogno
	  per spostare in cima alla lista il numero di cui sto calcolando il costo
 */

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

/* Calcolo mosse per raggiungere la testa dello stack */
long	cost_to_top_b(t_stack **stack, long size)
{
	long	i;
	long	j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = *stack;
	while (tmp && tmp->prev)
	{
		if (i < size / 2)
			j++;
		else
			j--;
		i++;
		tmp = tmp->prev;
	}
	if (i < size / 2)
		(*stack)->ops->rb = j;
	else
		(*stack)->ops->rrb = j;
	return (j);
}

// long	calculate_cost_bottom(t_stack **stack, long index, long n_r_rotate)
// {
// 	long	i;
// 	long	j;
// 	t_stack	*tmp;

// 	i = ft_list_size(*stack);
// 	j = 0;
// 	tmp = ft_list_last(*stack);
// 	while (j < i && tmp)
// 	{
// 		if (tmp->index > index  || index > (ft_list_find_node(*stack, find_biggest(stack)))->index)
// 			break ;
// 		tmp = tmp->prev;
// 		j++;
// 	}
// 	return (j + n_r_rotate + 1);
// }

/* void	push_in_a(t_stack **a, t_stack **b)
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
} */
