/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:12:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/11 18:24:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "javelo.h"

int main(int argc, char ** argv)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	get_next_line(pos.fd, &pos.line);
	printf("%s\n", pos.line);
	return (0);
}