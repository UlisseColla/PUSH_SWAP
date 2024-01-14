/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:22:11 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/14 19:14:05 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

/* 
	1. Definire una funzione cost() per calcolare quante mosse mi costa mettere un 
   	elemento al posto giusto nello stack
	2. definire funzione find_longest_route() per trovare la piu' lunga lista di numeri
	gia' oridnata
	3. Pushare gli elementi in B mettendoli in ordine decrescente
	4. Ripushare in A mettendoli al posto giusto, clacolando di volta in volta
	5. Ruotare nella direzione piu' conceninte per riordinare la lista

	2.
	--> a. creare un array di array **int, tanti quanti sono i numeri nello stack
		b. partire dal numero piu' grande al piu' piccolo e calcolare per ognuno
		la lista piu' lunga possibile fino al piu' piccolo
		c. alla fine calcolare quale array e' il piu' lungo e ritornarlo
*/

int	find_index(int *args, int num)
{
	int	i;

	i = 0;
	while (args[i] && args[i] != num)
		i++;
	return (i);
}

/* Creazione di array degli int passati come argomento a push_swap */
int	*create_array(t_stack *stack)
{
	long int		*array;
	int				i;
	t_stack	*tmp;

	array = (long int *)malloc(sizeof(long int) * (long)(ft_list_size(stack) + 1));
	i = 0;
	tmp = stack;
	while (tmp)
	{
		array[i] = tmp->index;
		i++;
		tmp = tmp->next;
	}
	array[i] = 2147483648;
	return (array);
}

/* Parametri sono array e indice e numero da cui partire */
/* All'inizio args[index] = num */
int	find_next_smaller(int *args, int num, int index)
{
	int	j;
	int	tmp;

	tmp = num - 1;
	while (tmp > 0)
	{
		j = index;
		while (args[j] && j >= 0)
		{
			if (args[j] == tmp)
				return (args[j]);
			j--;
		}
		tmp--;
	}
	return (num);
}

/* Funzione per trovare la sequenza piu' lunga. Parametro args = create_array() */
/* Parametro num e' il numero dal quale partire a fare la ricerca a ritroso (ordine decrescente) */
/* Se ho troppi linee passare i direttamente come argomento della funzione */
int	*find_longest_path(int *args, int num)
{
	int	i;
	int	j;
	int	k;
	int	tmp;
	int	*ret;	

	i = 1;
	j = find_index(args, num);
	k = j;
	tmp = num;
	while (find_next_smaller(args, tmp, j) != tmp)
	{
		i++;
		tmp = find_next_smaller(args, tmp, j);
		j = find_index(args, tmp);
	}
	ret = (long int *)malloc(sizeof(long int) * i);
	ret[i] = 2147483648;
	while (i > 0)
	{
		ret[i - 1] = num;
		i--;
		num = find_next_smaller(args, num, k);
		k = find_index(args, num);
	}
	return (ret);
}

/* !!! RIVEDERE PER BENE TUTTI I CAST A LONG !!! */

// int	*ret_longest_array(int *array)
// {
// 	int	i;
// 	int	**matrix;
// 	int	l;

// 	i = 0;
// 	while (array[i] != INT_MAX + 1)
// 		i++;
// 	matrix = (int **)malloc(sizeof(int *) * i);
// 	while (--i >= 0)
// 	{
// 		/* Funzione per trovare la sequenza piu' lunga */
// 		matrix[i] = find_longest_path(array, array[i]);
// 		while (l > 0)
// 		{
// 			printf("Matrix[i]: %d\n", matrix[i][l]);
// 			l--;
// 		}
// 	}
	
// }
