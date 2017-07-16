/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javelo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:04:53 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 13:47:42 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

int	check_solution(t_last *lst, t_pos *pos)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	while (elm != NULL)
	{
		while (res.i < pos->colun)
		{
			if (elm->contenta[res.i] != 0)
				return (-1);
			res.i++;
		}
		elm = elm->prev;
	}
	return (1);
}

int	action_line(t_last *lst, t_pos *pos, int nb)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	while (elm != NULL)
	{
		if (nb == elm->indice)
		{
			while (res.i < pos->colun)
			{
				elm->contenta[res.i] -= 1;
				res.i++;
			}
		}
		elm = elm->prev;
	}
	return (0);
}

int	action_colun(t_last *lst, t_pos *pos, int nb)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	printf("nb ====== %d\n", nb);
	printf("avant\n\n");
	elm = lst->fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			printf("[%d] ", elm->contenta[res.i]);
			res.i++;
		}
		printf("\n");
		elm = elm->prev;
	}
	elm = lst->fin;
	while (elm != NULL)
	{
		printf("indice [%d]\n", elm->indice);
		res.i = 0;
		while (res.i < pos->colun)
		{
			if (res.i == nb - 1)
			{
				printf("contenta = %d\n", elm->contenta[res.i]);
				elm->contenta[res.i] -= 2;
				break ;
				printf("contenta2 = %d\n", elm->contenta[res.i]);
			}
			res.i++;
		}
		break ;
		elm = elm->prev;
	}
	printf("TEST\n\n");
	elm = lst->fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			printf("[%d] ", elm->contenta[res.i]);
			res.i++;
		}
		printf("\n");
		elm = elm->prev;
	}
	return (0);
}

int		ft_duplicate_list(t_last *lst, t_last *dup, t_pos *pos)
{
	t_list	*elm;
	t_list	*tmp;
	t_res	res;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	if ((res.cut = (int*)malloc(sizeof(int) * (pos->colun + 1))) == NULL)
		return (-1);
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			res.cut[res.i] = elm->contenta[res.i];
			res.i++;
		}
		ft_add_elm_entier(dup, res.cut, pos->line1);
		tmp = dup->debut;
		tmp->num = elm->num;
		tmp->indice = elm->indice;
		elm = elm->prev;
	}
	return (-1);
}
