/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:08:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/02 16:29:49 by ucolla           ###   ########.fr       */
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

void	ft_free_matrix_lis(int **matrix, int size)
{
	int	i;

	if (matrix == NULL || *matrix == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	// free(matrix);
	// matrix[i] = NULL;
}
