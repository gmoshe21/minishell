/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:23:28 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/20 17:00:23 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem1;
	unsigned const char	*mem2;

	if (dest == src)
		return (dest);
	mem1 = (unsigned char *)dest;
	mem2 = (unsigned char *)src;
	while (n--)
		*mem1++ = *mem2++;
	return (dest);
}
