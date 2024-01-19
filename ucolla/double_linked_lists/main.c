/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/18 14:43:13 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

/* int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	// long	*path;
	int 	i;

	// Primo check dei parametri
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
	i = 0;
	index_stack_init(&a);
	path = ret_longest_array(create_array(a));
	index_push_init(a, path);
	while (path[i] != (long)INT_MAX + 1)
	{
		printf("path index: %ld\n", path[i]);
		i++;
	}
	show_stack(&a);

	return (0);	
} */

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	long	*path;
	int 	i;

	// Primo check dei parametri
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
	i = 0;
	index_stack_init(&a);
	path = ret_longest_array(create_array(a));
	index_push_init(a, path);
	push_in_b(&a, &b);
	// ft_printf("STACK_A\n");
	// show_stack(&a);
	// ft_printf("STACK_B\n");
	// show_stack(&b);
	push_in_a(&a, &b);
	ft_printf("STACK_A\n");
	show_stack(&a);
	ft_printf("STACK_B\n");
	show_stack(&b);

	return (0);
}

/* int main(void)
{
	long array[] = {23, 7, 32, 30, 6, 17, 31, 19, 22, 18, 8, 36, 12, 34, 28, 37, 38, 29, 33, 9, 10, 13, 27, 39, 1, 25, 40, 21, 24, 15, 20, 14, 16, 2, 3, 11, 5, 35, 4, 26, (long)INT_MAX + 1};

	long *b;
	b = NULL;
	b = ret_longest_array(array);
	int i = 0;
	while (b[i] != (long)INT_MAX + 1)
	{
		printf("b: %ld\n", b[i]);
		i++;
	}
	free(b);
	b = NULL;
} */