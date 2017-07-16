/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:49:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/12 14:15:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/javelo.h"

int		check_line(char *line, int len)
{
	t_res res;

	ft_memset(&res, 0, sizeof(t_res));
	while (line[res.i])
	{
		while (line[res.i] >= '0' && line[res.i] <= '9')
			res.i++;
		if (line[res.i] == ' ')
		{
			res.dup = ft_strsub(line, res.flag, res.i - res.flag);
			res.num = ft_atoi(res.dup);
			if (res.num >= 0)
				res.auth++;
			res.auth2++;
			res.flag = res.i;
		}
		res.i++;
	}
	res.dup = ft_strsub(line, res.flag, res.i - res.flag);
	res.num = ft_atoi(res.dup);
	if (res.num >= 0)
		res.auth++;
	if (res.auth2 == (len - 1) && (res.auth == len))
		return (1);
	return (0);
}

int		check_number(char *line, int on)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	if (ft_atoi(line) == 0)
	{
		ft_putstr("saisie incorrect");
		return (-1);
	}
	else
	{
		pos.num = ft_atoi(line);
		if ((pos.num > 100 && on == 1)|| (pos.num <= 1 && on == 0))
		{
			ft_putstr("le nombre doit etre compris entre 0 et 100");
			return (-1);
		}
	}
	pos.num = ft_atoi(line);
	return (pos.num);
}

int		*fill_tab(char *line, int taille)
{
	t_res res;

	ft_memset(&res, 0, sizeof(t_res));
	if ((res.cut = (int*)malloc(sizeof(int) * (taille + 1))) == NULL)
		return (NULL);
	while (line[res.i])
	{
		while (line[res.i] >= '0' && line[res.i] <= '9')
			res.i++;
		if (line[res.i] == ' ')
		{
			res.dup = ft_strsub(line, res.flag, res.i - res.flag);
			res.cut[res.j] = ft_atoi(res.dup);
			res.j++;
			res.flag = res.i;
		}
		res.i++;
	}
	res.dup = ft_strsub(line, res.flag, res.i -res.flag);
	res.cut[res.j] = ft_atoi(res.dup);
	return (res.cut);
}

int		recup_map(t_pos *pos, t_last *lst)
{
	t_res res;

	ft_memset(&res, 0, sizeof(t_res));
	while (res.i < pos->line1)
	{
		get_next_line(pos->fd, &res.dup);
		if (!check_line(res.dup, pos->colun))
		{
			printf("Le format est incorrect, n'oubliez pas l'espace (ex : \"1 3 2\")\n");
			return (-1);
		}
		res.cut = fill_tab(res.dup, pos->colun);
		ft_add_elm_entier(lst, res.cut, pos->colun);
		res.i++;
	}
	return (0);
}

int 	recup_info(t_pos *pos)
{
	ft_putstr("Nombre de ligne (<= 100) : ");
	get_next_line(pos->fd, &pos->line);
	pos->line1 = check_number(pos->line, 0);
	if (pos->line1 == -1)
		return (-1);
	ft_putstr("Nombre de colonne (<= 100): ");
	get_next_line(pos->fd, &pos->col);
	pos->colun = check_number(pos->col, 1);
	if (pos->colun == -1)
		return (-1);
	return (0);
}