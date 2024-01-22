/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:59:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 12:07:46 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

void	free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
}

static int	is_dup(char **mat, int a, int y)
{
	int	n1;
	int	n2;

	n1 = ft_atoi(mat[a]);
	n2 = ft_atoi(mat[y]);
	return (n1 - n2);
}

static int	check_dup(char **mat, int y)
{
	int	a;

	a = y;
	y++;
	while (mat[y])
	{
		if (is_dup(mat, a, y) == 0)
			return (1);
		y++;
	}
	return (0);
}

int	check_sign_and_chars(char **mat, int i, int j)
{
	while (mat[i][j])
	{
		if (mat[i][j] == '-' || mat[i][j] == '+')
			j++;
		if ((mat[i][j] < 48) || (mat[i][j] > 57))
			return (1);
		j++;
	}
	return (0);
}

int	check_input(char *str)
{
	char	**mat;
	int		i;

	i = 0;
	mat = ft_split(str, ' ');
	while (mat[i])
	{
		if (check_sign_and_chars(mat, i, 0) == 1
			|| ft_atol(mat[i]) > 2147483647 || ft_atol(mat[i]) < -2147483648
			|| check_dup(mat, i) == 1)
		{
			free_mat(mat);
			mat = NULL;
			return (1);
		}
		i++;
	}
	free_mat(mat);
	mat = NULL;
	return (0);
}
