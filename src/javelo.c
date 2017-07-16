/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javelo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:04:53 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 19:40:57 by hel-hadi         ###   ########.fr       */
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
		res.i = 0;
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
	elm = lst->fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos->colun)
		{
			if (res.i == nb - 1)
				elm->contenta[res.i] -= 1;
			res.i++;
		}
		elm = elm->prev;
	}
	return (0);
}
