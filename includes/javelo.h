/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javelo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:13:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/16 18:31:10 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JAVELO_H
# define JAVELO_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_pos
{
	int			i;
	int			shot_line;
	int			shot_colun;
	int			fd;
	int			num;
	int			line1;
	int			colun;
	char		**map;
	char		*col;
	char		*line;
}				t_pos;

typedef struct	s_res
{
	int			i;
	int			j;
	int			k;
	int			num;
	int			auth;
	int			auth2;
	int			flag;
	int			min;
	int			*cut;
	int			*rel;
	char		*dup;
	char		*line;
}				t_res;

int 			recup_info(t_pos *pos);
int				recup_map(t_pos *pos, t_last *dup, t_last *lst);
int				regul_colun(t_last* lst, t_pos *pos, int colun, int val);
int				find_min_colun(t_last *lst, t_pos *pos);
void			tab_min_colun(t_last *lst, t_pos *pos);
int				solve_puzzle(t_last *lst, t_last *dup, t_pos *pos);
int				action_colun(t_last *lst, t_pos *pos, int nb);
int				action_line(t_last *lst, t_pos *pos, int nb);
int				*solve_coluns(t_last *lst, t_last *dup, t_pos *pos);
int				check_solution(t_last *lst, t_pos *pos);
void			print_solve(int *tab, int *tab2, t_pos *pos, int tour);

#endif