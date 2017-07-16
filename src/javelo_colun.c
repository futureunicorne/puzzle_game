/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javelo_colun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:04:53 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 13:52:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

int		resolve_colun(t_last *lst, t_pos *pos, int len)
{
	t_res	res;
	t_list	*elm;

	elm = lst->fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			if (res.i == len - 1)
			{
				printf("res.i = %d\n", elm->contenta[res.i]);
				if (elm->contenta[res.i] <= 0)
				{
					//printf("res.i = %d\n", elm->contenta[res.i + 1]);
					//printf("res.i = %d\n", elm->contenta[res.i + 2]);
					return (-1);
				}
			}
			res.i++;
		}
		elm = elm->prev;
	}
	return (1);
}
int		regul_colun(t_last* lst, t_pos *pos, int colun, int val)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	res.j = 1;
	while (res.i < pos->colun)
	{
		if (res.i == colun)
		{
			elm->tab_colun[res.i][res.j] = val;
			res.j++;
			elm->tab_colun[res.i][res.j] = colun + 1;
			break ;
		}
		res.i++;
	}
	return (0);
}

int		find_min_colun(t_last *lst, t_pos *pos)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	if ((elm->tab_colun = (int**)malloc(sizeof(int*) * (pos->colun + 1))) == NULL)
		return (-1);
	while (res.j < pos->colun)
	{
		if ((elm->tab_colun[res.j] = (int*)malloc(sizeof(int) * (2 + 1))) == NULL)
			return (-1);
		res.j++;
	}
	while (res.flag < pos->colun)
	{
		elm = lst->fin;
		while (elm != NULL)
		{
			res.i = 0;
			if (res.i == 0 && elm->indice == 1)
			{
				res.auth = elm->contenta[res.flag];
			}
			while (res.i < pos->colun)
			{
				if (res.i == res.flag)
				{
					if (elm->contenta[res.i] < res.auth)
						res.auth = elm->contenta[res.i];
				}
				res.i++;
			}
			elm = elm->prev;
		}
		regul_colun(lst, pos, res.flag, res.auth);
		res.flag++;
	}
	return (0);
}

void	range_tab(t_last *lst, t_last *dup, t_pos *pos)
{
	t_res	res;
	t_list	*elm;

	ft_memset(&res, 0, sizeof(t_res));
	elm = lst->fin;
	while (res.i < pos->colun)
	{
		res.j = 0;
		while (res.j < pos->colun)
		{
			res.num = 0;
			res.flag = 0;
			if (elm->tab_colun[res.j][1] > elm->tab_colun[res.i][1])
			{
				res.num = elm->tab_colun[res.i][1];
				elm->tab_colun[res.i][1] = elm->tab_colun[res.j][1];
				elm->tab_colun[res.j][1] = res.num;
				res.flag = elm->tab_colun[res.i][2];
				elm->tab_colun[res.i][2] = elm->tab_colun[res.j][2];
				elm->tab_colun[res.j][2] = res.flag;
			}
			res.j++;
		}
		res.i++;
	}

}

int		solve_coluns(t_last *lst, t_last *dup, t_pos *pos)
{
	t_res	res;
	t_list	*tmp;

	ft_memset(&res, 0, sizeof(t_res));
	find_min_colun(lst, pos);
	range_tab(lst, dup, pos);
	tmp = lst->fin;
	while (res.i )
	{

	}
	while (res.i < pos->colun)
	{
		//printf("val = %d\n", tmp->tab_colun[res.i][1]);
		//printf("colun = %d\n", tmp->tab_colun[res.i][2]);
		if (resolve_colun(lst, pos, tmp->tab_colun[res.i][2]) == -1)
			printf("oui\n");
		else
		{
			action_colun(dup, pos, tmp->tab_colun[res.i][2]);
		}
		res.i++;
	}
}