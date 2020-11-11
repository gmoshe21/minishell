/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:25:03 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/22 15:31:18 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int y;
	int b;

	i = ft_strlen(dst);
	y = ft_strlen(src);
	b = i + y;
	if ((int)size >= i)
	{
		size = size - i;
		while (size > 1 && *src != '\0')
		{
			dst[i++] = *src++;
			size--;
		}
		if (size != 0)
			dst[i] = '\0';
		return (b);
	}
	else
		return (y + size);
}
