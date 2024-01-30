/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/30 18:47:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

static int	array_size(int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
		i++;
	return (i);
}

static int	many_parameters(char **argv, t_stack **stack)
{
	char	*str;
	char	*str2;
	int		i;

	str = NULL;
	str2 = NULL;
	i = 0;
	while (argv[++i])
	{
		str = ft_strjoin(argv[i], " ");
		str2 = ft_strjoin_ps(str2, str);
		free(str);
	}
	if (check_input(str2) != 0)
	{
		free(str2);
		return (1);
	}
	*stack = ft_create_list(str2);
	free(str2);
	return (0);
}

static int	check_argv(char **argv, int argc, t_stack **stack)
{
	if (argc == 2)
	{
		if (check_input(argv[1]) == 1 || argc < 2)
			return (1);
		*stack = ft_create_list(argv[1]);
		return (0);
	}
	else if (argc < 2)
	{
		ft_putstr_fd("No parameters\n", 2);
		return (1);
	}
	else
		return (many_parameters(argv, stack));
}

int	*find_longest_lis(t_lis **lis, int list_size)
{
	int	counter;
	int	current_value;
	int	biggest_length;
	int	*lis_path;
	int	*final_lis;

	counter = 0;
	current_value = 0;
	biggest_length = 0;
	lis_path = NULL;
	final_lis = NULL;
	while (counter < list_size)
	{
		lis_path = ft_circular_lis(lis, list_size);
		biggest_length = array_size(lis_path);
		if (biggest_length > current_value)
		{
			current_value = biggest_length;
			final_lis = lis_path;
		}
		*lis = (*lis)->next;
		counter++;
	}
	return (final_lis);
}

int	initialize_stack(t_stack **stack, char **argv, int argc)
{
	int		list_size;
	int		*lis_path;
	t_lis	*lis;

	lis = NULL;
	if (check_argv(argv, argc, stack) == 1)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	list_size = ft_list_size(stack);
	index_stack_init(stack);
	lis = index_lis_init(stack, list_size);
	lis_path = find_longest_lis(&lis, list_size);
	index_push_init(*stack, lis_path);
	free(lis_path);
	return (0);
}
