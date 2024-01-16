/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:22:11 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/16 15:27:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

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

	Due logiche diverse di ricerca della sequenza di indici gia' in ordine:
	
	I. find_next_smaller() parte dall'indice index passato come argomento e procede cercando
		index--;
	II. ft_smaller() parte dall'indice index passato come argomento e procede cercando il 
		prossimo numero piu' piccolo, non importa quanto piu' piccolo.
*/

long	find_index(long *args, long num)
{
	long	i;

	i = 0;
	while (args[i] && args[i] != num)
		i++;
	return (i);
}

/* Creazione di array degli int passati come argomento a push_swap */
long	*create_array(t_stack *stack)
{
	long	*array;
	int		i;
	t_stack	*tmp;

	array = (long *)malloc(sizeof(long) * (long)(ft_list_size(stack) + 1));
	i = 0;
	tmp = stack;
	while (tmp)
	{
		array[i] = (long)tmp->index;
		i++;
		tmp = tmp->next;
	}
	array[i] = (long)INT_MAX + 1;
	return (array);
}

/* Trova il prossimo numero piu' piccolo */
long	ft_smaller(long *args, long num, long index)
{
	while (index >= 0)
	{
		if (args[index] < num)
			return (args[index]);
		index--;
	}
	return (num);
}

/* Parametri sono array e indice e numero da cui partire */
/* All'inizio args[index] = num */
long	find_next_smaller(long *args, long num, long index)
{
	long	j;
	long	tmp;

	j = 0;
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
long	*find_longest_path(long *args, long num, long i)
{
	long	j;
	long	k;
	long	tmp;
	long	*ret;	

	j = find_index(args, num);
	k = j;
	tmp = num;
	while (ft_smaller(args, tmp, j) != tmp)
	{
		i++;
		tmp = ft_smaller(args, tmp, j);
		j = find_index(args, tmp);
	}
	ret = (long *)malloc(sizeof(long) * i + 1);
	ret[i - 1] = (long)INT_MAX + 1;
	i -= 2;
	while (i >= 0)
	{
		ret[i] = num;
		i--;
		num = ft_smaller(args, num, k);
		k = find_index(args, num);
	}
	return (ret);
}

/* parametro array --> create_array() */
long	*ret_longest_array(long *array)
{
	long	i;
	long	*longest;
	long	*tmp;

	i = array_size(array) - 1;
	longest = NULL;
	while (i >= 0)
	{
		tmp = find_longest_path(array, array[i], 1);
		if (array_size(tmp) > array_size(longest))
			longest = tmp;
		else
			free(tmp);
		i--;
	}
	return (longest);
}
