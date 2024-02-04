/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 15:45:20 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_ps(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;

	ret = (char *)ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1,
			sizeof(char));
	a = 0;
	b = 0;
	while (s1 && s1[a] != '\0')
	{
		ret[a] = s1[a];
		a++;
	}
	while (s2 && s2[b] != '\0')
	{
		ret[a] = s2[b];
		a++;
		b++;
	}
	ret[a] = '\0';
	free(s1);
	return (ret);
}

int	many_parameters(char **argv, t_stack **stack)
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

int	check_argv(char **argv, int argc, t_stack **stack)
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

int	initialize_stack(t_stack **stack, char **argv, int argc)
{
	if (check_argv(argv, argc, stack) == 1)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	index_stack_init(stack, 1, 1);
	return (0);
}
