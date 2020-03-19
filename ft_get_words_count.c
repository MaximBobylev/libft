/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_words_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:54:00 by hbits             #+#    #+#             */
/*   Updated: 2019/10/22 22:54:23 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_words_count(char *s, char c)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (s[i] != c && s[i])
	{
		i++;
		num++;
	}
	else if (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			num++;
		i++;
	}
	return (num);
}
