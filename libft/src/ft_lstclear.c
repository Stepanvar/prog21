/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:20:17 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/15 17:38:44 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nemo;

	if (lst && del)
	{
		while (*lst)
		{
			nemo = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nemo;
		}
	}
}
