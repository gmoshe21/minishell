/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 20:12:53 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/21 20:24:29 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num(char const *news, char const *newset)
{
	int	p;
	int	x;

	p = 0;
	x = 0;
	while (newset[p] != '\0' && news[x] != 0)
	{
		while (newset[p] != news[x] && newset[p] != '\0')
			p++;
		if (newset[p] == news[x])
		{
			p = 0;
			x++;
		}
	}
	return (x);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	j;
	int	p;
	int	x;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1;
	p = 0;
	x = num(s1, set);
	while (set[p] != '\0' && s1[x] != 0)
	{
		while (set[p] != s1[j] && set[p] != '\0')
			p++;
		if (set[p] == s1[j])
		{
			p = 0;
			j--;
		}
	}
	j -= x;
	return (ft_substr(s1, x, j + 1));
}
