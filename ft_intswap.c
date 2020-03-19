/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:33:32 by kdune             #+#    #+#             */
/*   Updated: 2019/11/25 20:22:00 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intswap(int *first, int *second)
{
	int	tmp;

	if (!first || !second)
		return ;
	tmp = *first;
	*first = *second;
	*second = tmp;
}
