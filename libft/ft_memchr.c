/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:57:21 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/20 17:17:09 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char		*a;
	unsigned char		co;

	a = (unsigned char *)arr;
	co = (unsigned char)c;
	while (n--)
	{
		if (*a == co)
			return (a);
		a++;
	}
	return (NULL);
}
