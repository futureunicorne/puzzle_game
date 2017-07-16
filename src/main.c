/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:40:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 20:09:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

void	print_solve_bis(int *tab, int *tab2, t_pos *pos, int tour)
{
	t_res	res;

	ft_memset(&res, 0, sizeof(t_res));
	res.flag = pos->shot_colun;
	if (tab != NULL)
	{
		while (res.i < res.flag)
		{
			printf("col %d\n", tab[res.i]);
			res.i++;
		}
		res.flag = pos->shot_line;
		if (tab2)
		{
			while (res.j < res.flag)
			{
				printf("row %d\n", tab2[res.j]);
				res.j++;
			}
		}
	}
}

void	print_solve(int *tab, int *tab2, t_pos *pos, int tour)
{
	t_res	res;

	ft_memset(&res, 0, sizeof(t_res));
	printf("\nSolution en %d coups\n\n", pos->shot_colun + pos->shot_line);
	return ;
	if (tour == 2)
	{
		print_solve_bis(tab, tab2, pos, tour);
		return ;
	}
	res.flag = pos->shot_line;
	if (tab != NULL)
	{
		while (res.i < res.flag)
		{
			printf("row %d\n", tab[res.i]);
			res.i++;
		}
		res.flag = pos->shot_colun;
		if (tab2 != NULL)
		{
			while (res.j < res.flag)
			{
				printf("col %d\n", tab2[res.j]);
				res.j++;
			}
		}
	}
}

int main(int argc, char **argv)
{
	t_pos pos;
	t_res res;
	t_last lst;
	t_last dup;
	t_list *elm;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&res, 0, sizeof(t_res));
	ft_init_lst(&lst);
	ft_init_lst(&dup);
	if (recup_info(&pos) == -1)
		return (0);
	if (recup_map(&pos, &lst, &dup) == -1)
		return (0);
	if (solve_puzzle(&lst, &dup, &pos) == -1)
	{
		printf("-1 : Solution Impossible\n");
		return (-1);
	}
	return (0);
}