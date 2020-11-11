/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:59:47 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/03 21:50:55 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = ft_strlen(str);
	while (str[i] != ch && i != 0)
		i--;
	if (str[i] == ch)
		return ((char *)&str[i]);
	else
		return (NULL);
}
