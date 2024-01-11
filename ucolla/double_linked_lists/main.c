/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/11 14:46:19 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = ft_create_list(argc, argv);
	b = NULL;
/*
	push_b(&b, &a);
	push_b(&b, &a);
	push_b(&b, &a);
	push_b(&b, &a);

	swap_b(&b);
	swap_a(&a);
	
	reverse_rotate_a(&a);
	reverse_rotate_b(&b);
*/
	while (a)
	{
		printf("a: %d, index: %d, has_index: %d\n", a->value, a->index, a->has_index);
		a = a->next;
	}
	write(1, "\n", 1);
	while (b)
	{
		printf("b: %d\n", b->value);
		b = b->next;
	}
	return (0);
}
	
