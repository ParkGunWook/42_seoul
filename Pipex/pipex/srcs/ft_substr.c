/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:18:10 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 15:53:34 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	max_len;

	if (s == NULL)
		return (NULL);
	max_len = ft_strlen(s);
	if (max_len <= start)
	{
		new = (char*)malloc(sizeof(char) * 1);
		new[0] = 0;
		return (new);
	}
	max_len = ft_strlen(s + start);
	if (max_len < len)
		len = max_len;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	*(new + len) = 0;
	return (new);
}
