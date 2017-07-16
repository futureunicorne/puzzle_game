/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:14:12 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/07/12 19:45:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_add_elm(t_last *list, void *content, size_t content_size, int rep)
{
	t_list *elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (-1);
	if ((elem->content = malloc(content_size)) == NULL)
		return (-1);
	free(elem->content);
	elem->content_size = content_size;
	elem->content = content;
	elem->next = list->debut;
	elem->prev = NULL;
	if (list->debut)
		list->debut->prev = elem;
	else
		list->fin = elem;
	list->debut = elem;
	list->taille++;
	elem->repere = rep;
	return (0);
}

int	ft_add_elm_bis(t_last *list, void *content, size_t content_size)
{
	t_list *elem;

	if ((elem = (t_list*)malloc(sizeof(*elem))) == NULL)
		return (-1);
	ft_memset(elem, 0, sizeof(t_list));
	elem->content = NULL;
	elem->content_size = content_size;
	elem->content = ft_strdup((char*)content);
	elem->next = list->debut;
	elem->prev = NULL;
	if (list->debut)
		list->debut->prev = elem;
	else
		list->fin = elem;
	list->debut = elem;
	list->taille++;
	return (0);
}

int	ft_add_elm_entier(t_last *list, void *content, size_t content_size)
{
	t_list *elem;

	if ((elem = (t_list*)malloc(sizeof(*elem))) == NULL)
		return (-1);
	ft_memset(elem, 0, sizeof(t_list));
	elem->content = NULL;
	elem->content_size = content_size;
	elem->contenta = content;
	elem->next = list->debut;
	elem->prev = NULL;
	if (list->debut)
		list->debut->prev = elem;
	else
		list->fin = elem;
	list->debut = elem;
	list->taille++;
	elem->indice = list->taille;
	return (0);
}
