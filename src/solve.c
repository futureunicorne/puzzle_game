/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:43:43 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 13:52:06 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../includes/javelo.h"

int		resolve_line(int *tab, int len)
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

int		find_min_line(t_last *lst, t_pos *pos)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	if ((res.cut = (int*)malloc(sizeof(int) * (pos->line1 + 1))) == NULL)
		return (-1);
	elm = lst->fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			if (res.i == 0)
				res.auth = elm->contenta[res.i];
			if (elm->contenta[res.i] < res.flag)
			{
				res.auth = elm->contenta[res.i];
			}
			res.i++;
		}
		elm->num = res.auth;
		elm = elm-> prev;
	}
	return (0);
}

void	tab_min_line(t_last *lst, t_last *dup, t_pos *pos)
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

int		solve_line(t_last *lst, t_last *dup, t_pos *pos)
{
	t_res	res;
	t_list	*tmp;

	ft_memset(&res, 0, sizeof(t_res));
	tab_min_line(lst, dup, pos);
	tmp = dup->fin;
	while (tmp != NULL)
	{
		if (resolve_line(tmp->contenta, pos->colun) == -1)
			tmp = tmp->prev;
		else
			action_line(dup, pos, tmp->indice);
	}
	return (-1);
}

int		solve_puzzle(t_last *lst, t_pos *pos)
{
	t_res	res;
	t_last	dup;
	t_list	*tmp;
	ft_memset(&res, 0, sizeof(t_res));
	ft_init_lst(&dup);
	if (pos->line1 <= pos->colun)
	{
		if (solve_line(lst, &dup, pos) == -1)
		{
			if (solve_coluns(lst, &dup, pos) == -1)
				return (-1);
		}
	}
	else
	{
		//if (solve_coluns(lst, &dup, pos) == -1)
		//{
			//if(solve_line() == -1)
			//	return (-1)
		//}
	}
	if (check_solution(&dup, pos) == 1)
		printf("%s\n", "resolu");
	else
		printf("-1 Solution Impossible\n");
	return (0);
}