/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/14 19:09:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

/* int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	int file = open("ARGS", O_RDONLY, 0666);
	(void)argv;
	if (check_input(get_next_line(file)) == 1 || argc < 0)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	else
	{
		int file = open("ARGS", O_RDONLY, 0666);
		a = ft_create_list(get_next_line(file));
	}
	b = NULL;
	
	index_stack_init(&a);
	
	int *b = ret_longest_array()
	while (b[i])
	{
		printf("array: %d\n", b[i]);
		i++;
	}
	show_stack(&a);
	show_stack(&c);

	return (0);	
} */

int main(void)
{
	// int a[] = {1, 5, 7, 3, 9, 2, 16, 15, 58};
	int array[] = {86, 977, 475, 903, 680, 621, 885, 62, 54, 454, 510, 7, 669, 817, 103, 326, 460, 476, 133, 928};


	int *b = find_longest_path(array, 669);

	// printf("array: %d\n", b[i]);
	while (b[i] != 2147483648)
	{
		printf("b: %d\n", b[i]);
		i++;
	}
	// printf("i: %d\n", length);
}