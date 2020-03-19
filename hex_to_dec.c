/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:28:58 by hbits             #+#    #+#             */
/*   Updated: 2020/03/04 13:29:03 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	hex_to_dec(char c)
{
	const char		alph_low[] = "0123456789abcdef";
	const char		alph_up[] = "0123456789ABCDEF";
	unsigned char	i;

	i = 0;
	while (alph_low[i])
	{
		if (alph_low[i] == c)
			return (i);
		i++;
	}
	i = 10;
	while (alph_up[i])
	{
		if (alph_up[i] == c)
			return (i);
		i++;
	}
	return (0);
}
