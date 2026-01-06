/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:58:28 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 08:59:13 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // librairie pour importe NULL


typedef struct    s_list // stucture deja donne
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int	count = 0; // count qui va contenir le nombre de maillons de la liste
	if (!begin_list) // return 0 si il n'ya pas de liste
		return (0);
	while (begin_list != NULL) // tant que la liste existe on passe au maillon suivant
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}