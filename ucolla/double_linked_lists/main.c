/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/11 14:46:19 by aconciar         ###   ########.fr       */
=======
/*   Updated: 2024/01/10 19:35:52 by ucolla           ###   ########.fr       */
>>>>>>> f65d8b8d2ca0f7e21b7c04e456972d3f78c3dde7
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = ft_create_list(argc, argv);
	b = NULL;

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
	
