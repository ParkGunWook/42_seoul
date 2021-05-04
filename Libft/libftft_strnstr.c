/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:37:24 by gpark             #+#    #+#             */
/*   Updated: 2021/03/30 14:37:48 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_from_str(char *str, char *to_find)
{
	while (*to_find != 0)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

char		*ft_strstr(char *str, char *to_find)
{
	if (*to_find == 0)
		return (str);
	while (*str != 0)
	{
		if (find_from_str(str, to_find) == 1)
		{
			return (str);
		}
		str++;
	}
	return (0);
}
