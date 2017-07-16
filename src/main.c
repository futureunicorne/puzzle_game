/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:40:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/12 14:30:44 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

int main(int argc, char **argv)
{
	t_pos pos;
	t_res res;
	t_last lst;
	t_list *elm;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&res, 0, sizeof(t_res));
	ft_init_lst(&lst);

	if (recup_info(&pos) == -1)
		return (0);
	if (recup_map(&pos, &lst) == -1)
		return (0);
	printf("\n");
	elm = lst.fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos.colun)
		{
			printf("[%d] ", elm->contenta[res.i]);
			res.i++;
		}
		printf("\n");
		elm = elm->prev;
	}
	if (solve_puzzle(&lst, &pos) == -1)
	{
		printf("-1 : Solution Impossible\n");
		return (-1);
	}
	printf("\n");
	printf("New One\n");
	elm = lst.fin;
	while (elm != NULL)
	{
		res.i = 0;
		while (res.i < pos.colun)
		{
			printf("[%d] ", elm->contenta[res.i]);
			res.i++;
		}
		printf("\n");
		elm = elm->prev;
	}
	return (0);
}