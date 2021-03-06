/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad2deg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:45 by hbits             #+#    #+#             */
/*   Updated: 2020/03/05 16:02:55 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		rad2deg(float rad)
{
	const float	pi = 3.1415927;

	return (rad * 180 / pi);
}
