/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:34:58 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:01:58 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nemo;
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		while (lst)
		{
			nemo = ft_lstnew((*f)(lst->content));
			if (!nemo)
			{
				while (new)
				{
					nemo = new->next;
					ft_lstdelone(new, del);
					new = nemo;
				}
			}
			ft_lstadd_back(&new, nemo);
			lst = lst->next;
		}
	}
	return (new);
}
