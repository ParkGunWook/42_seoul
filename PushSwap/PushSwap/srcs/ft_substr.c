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

#include "myloc.h"
#include "utils.h"

static	int	strChecker(char *new)
{
	int		i;

	i = 0;
	if (new[i] == '+' || new[i] == '-')
		i++;
	while (new[i] != 0)
	{
		if ('0' > new[i] || new[i] > '9')
		{
			myFree((void **)&new);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	max_len;

	if (s == NULL)
		return (NULL);
	max_len = ft_strlen(s);
	if (max_len <= start)
	{
		myAloc((void **)&new, 1);
		if (!new)
			return (NULL);
		new[0] = 0;
		return (new);
	}
	max_len = ft_strlen(s + start);
	if (max_len < len)
		len = max_len;
	myAloc((void **)&new, len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	*(new + len) = 0;
	if (strChecker(new) == 0)
		return (NULL);
	return (new);
}
