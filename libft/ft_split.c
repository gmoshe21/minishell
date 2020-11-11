/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:33:24 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/25 20:07:09 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		letsfree(char **str)
{
	int			i;

	i = 0;
	while (str)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char		**napoln(char **rez, char const *s3, char c3)
{
	int			i;
	int			j;
	int			p;

	i = 0;
	j = 0;
	p = 0;
	while (s3[i])
	{
		while (s3[i++] != c3)
		{
			j++;
			if (s3[i] != c3 && s3[i] != '\0')
				continue;
			rez[p++] = ft_substr(s3, i - j, j);
			if (!rez)
				letsfree(rez);
			j = 0;
			while (s3[i] == c3 && s3[i] != '\0')
				i++;
			if (s3[i] == '\0')
				return (rez);
		}
	}
	return (rez);
}

static int		memory(char const *s2, char c2, int j)
{
	int			num;

	num = 0;
	while (s2[num])
	{
		while (s2[num] != c2 && s2[num] != '\0')
		{
			num++;
			if (s2[num] == c2 && s2[num] != '\0')
				j++;
			if (s2[num - 1] != c2 && s2[num] == '\0')
				j++;
		}
		while (s2[num] == c2 && s2[num] != '\0')
			num++;
		if (s2[num] == '\0')
			return (j);
	}
	return (j);
}

char			**ft_split(char const *s, char c)
{
	char		**str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	i = memory(s, c, i);
	str = ft_calloc(i + 1, sizeof(char**));
	if (!str)
		return (NULL);
	str = napoln(str, s, c);
	if (!str)
		return (NULL);
	return (str);
}
