/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:39:13 by gpark             #+#    #+#             */
/*   Updated: 2021/05/05 00:05:52 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		idx;
	char		*new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	idx = 0;
	ft_strlcpy(new, s1, s1_len + s2_len + 1);
	ft_strlcpy(new + s1_len, s2, s1_len + s2_len + 1);
	*(new + s1_len + s2_len) = 0;
	return (new);
}
