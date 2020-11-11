/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:04:44 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/26 00:21:10 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t s)
{
	size_t len;

	len = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && len <= s)
	{
		s--;
		if (*s1 == *s2 && !ft_strncmp(s1, s2, len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
