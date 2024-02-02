/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:27:36 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 10:50:13 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* crea nodo lis */
t_lis	*ft_node_lis(int index)
{
	t_lis	*new;

	new = (t_lis *)malloc(sizeof(t_lis));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->lis_index = 0;
	new->length = 1;
	new->next = NULL;
	return (new);
}

/* aggiungi nodo in fono alla lis */
void	ft_addback_lis(t_lis **list, t_lis *new)
{
	t_lis	*tmp;

	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

/* scorri fino all'ultimo nodo della lis */
t_lis	*ft_last_lis(t_lis *list)
{
	int	head;

	head = list->index;
	if (!list)
		return (NULL);
	while (list->next && list->next->index != head)
		list = list->next;
	return (list);
}

/* trovo nodo in lis in base a index */
t_lis	*ft_find_in_lis(t_lis **lis, int index, int size)
{
	t_lis	*tmp;
	int		i;

	tmp = *lis;
	i = 0;
	while (i < size)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

/* trovo nodo in lis in base a lis_index */
t_lis	*ft_find_lis_index(t_lis **lis, int lis_index, int size)
{
	t_lis	*tmp;
	int		i;

	tmp = *lis;
	i = 0;
	while (i < size)
	{
		if (tmp->lis_index == lis_index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}
