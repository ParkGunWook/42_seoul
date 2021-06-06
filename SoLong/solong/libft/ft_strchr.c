/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:56:24 by gpark             #+#    #+#             */
/*   Updated: 2021/05/04 20:24:32 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx))
	{
		if (*(s + idx) == (char)c)
			return (char*)(s + idx);
		idx++;
	}
	if (*(s + idx) == (char)c)
		return (char*)(s + idx);
	else
		return (NULL);
}
