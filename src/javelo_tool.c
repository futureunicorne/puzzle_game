/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javelo_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:04:53 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/14 18:18:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

int		resolve_colun(int *tab, int len)
{
	t_res	res;

	ft_memset(&res, 0, sizeof(t_res));
	while (res.i < len)
	{
		if (tab[res.i] <= 0)
			return (-1);
		res.i++;
	}
	return (1);
}
void	regul_colun(t_last* lst, int colun, int val)
{
	t_res	res;
	t_list	*elm;

	if ((elm->tab_colun = (int*)malloc(sizeof(int) * (pos->coluns + 1))) == NULL)
		return (-1);
	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	while (res.i < pos->colun)
	{
		if (res.i == colun)
		{
			elm->tab_colun[res.j] = val;
			res.j++;
		}
		res.i++;
	}
}

int		find_min_colun(t_last *lst, t_pos *pos)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	if ((elm->tab_colun = (int*)malloc(sizeof(int) * (pos->coluns + 1))) == NULL)
		return (-1);
	while (res.flag < pos->colun)
	{
		elm = lst->fin;
		while (elm != NULL)
		{
			res.i = 0;
			if (res.i == 0 && elm->indice == 1)
				res.auth = elm->contenta[res.i];
			while (res.i < pos->colun)
			{
				if (res.i == nb)
				{
					if (elem->contenta[res.i] < res.auth)
						res.auth = elm->contenta[res.i];
				}
				res.i++;
			}
			elm = elm->prev;
		}
		regul_colun(lst, res.flag, res.auth);
		res.flag++;
	}
	return (0);
}

void	tab_min_colun(t_last *lst, t_last *dup, t_pos *pos)
{
	t_res	res;
	t_list	*tmp;
	t_list	*tmp2;

	ft_memset(&res, 0, sizeof(t_res));
	find_min_line(lst, pos);
	ft_duplicate_list(lst, dup, pos);
	tmp = dup->fin;
	while (tmp != NULL)
	{
		tmp2 = dup->fin;
		while (tmp2 != NULL)
		{
			if (tmp2->num > tmp->num)
			{
				res.cut = tmp2->contenta;
				res.min = tmp2->indice;
				res.num = tmp2->num;
				tmp2->contenta = tmp->contenta;
				tmp2->indice = tmp->indice;
				tmp2->num = tmp->num;
				tmp->contenta = res.cut;
				tmp->indice = res.min;
				tmp->num = res.num;
			}
			tmp2 = tmp2->prev;
		}
		tmp = tmp->prev;
	}
}

int		solve_coluns(t_last *lst, t_last *dup, t_pos *pos)
{
	t_res	res;
	t_list	*tmp;

	ft_memset(&res, 0, sizeof(t_res));
	tab_min_colun(lst, dup, pos);
	tmp = dup->fin;
	/*
	while (tmp != NULL)
	{
		if (resolve_colun(tmp->contenta, pos->colun) == -1)
			tmp = tmp->prev;
		else
			action_colun(dup, pos, 3);
	}
	*/
}