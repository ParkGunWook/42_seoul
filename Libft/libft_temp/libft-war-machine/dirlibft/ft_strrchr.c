/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:59:23 by gpark             #+#    #+#             */
/*   Updated: 2021/05/03 21:08:03 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	size_t	idx;
	char	*ret;

	idx = 0;
	ret = NULL;
	while (*(s + idx))
	{
		if (*(s + idx) == (char)c)
			ret = (char*)(s + idx);
		idx++;
	}
	if (*(s + idx) == (char)c)
		return (char*)(s + idx);
	else
		return (NULL);
}
