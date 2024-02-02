/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/02 19:37:37 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int **alloc_matrix(int list_size)
{
	int	i;
	int	**matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * list_size);
	if (matrix == NULL)
	{
		ft_free_matrix_lis(matrix, list_size);
		return (NULL);
	}
	while (i < list_size)
	{
		matrix[i] = NULL;
		i++;
	}
	return (matrix);
}

int	*find_longest_lis(t_lis **lis, int list_size, int counter, int current_value)
{
	int	biggest_length;
	int	*final_lis;
	int	**matrix;

	biggest_length = 0;
	matrix = alloc_matrix(list_size);
	final_lis = NULL;
	while (counter < list_size)
	{
		matrix[counter] = ft_circular_lis(lis, list_size);
		biggest_length = array_size(matrix[counter]);
		if (biggest_length > current_value)
		{
			current_value = biggest_length;
			final_lis = matrix[counter];
		}
		*lis = (*lis)->next;
		counter++;
	}
	// ft_free_matrix_lis(matrix, list_size);
	matrix = NULL;
	return (final_lis);
}

/* int	*find_longest_lis_tmp(t_lis **lis, int list_size, int counter, int current_value)
{
	int	biggest_length;
	int	*tmp_lis;
	int	*final_lis;

	biggest_length = 0;
	final_lis = NULL;
	// tmp_lis = NULL;
	while (counter < list_size)
	{
		tmp_lis = ft_circular_lis(lis, list_size);
		biggest_length = array_size(tmp_lis);
		if (biggest_length > current_value)
		{
			current_value = biggest_length;
			final_lis = tmp_lis;
		}
		else
			free(tmp_lis);
		tmp_lis = NULL;
		*lis = (*lis)->next;
		counter++;
	}
	return (final_lis);
} */

int	initialize_stack(t_stack **stack, char **argv, int argc)
{
	t_lis	*lis;
	int		*lis_path;
	int		list_size;
	int		head_lis;

	lis = NULL;
	if (check_argv(argv, argc, stack) == 1)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	list_size = ft_list_size(stack);
	index_stack_init(stack);
	if (list_size > 5)
	{
		lis = index_lis_init(stack, list_size);
		head_lis = lis->index;
		lis_path = find_longest_lis(&lis, list_size, 0, 0);
		index_push_init(*stack, lis_path);
		ft_free_lis(lis, head_lis);
		free(lis_path);
	}
	return (0);
}
