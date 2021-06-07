/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:24:20 by gpark             #+#    #+#             */
/*   Updated: 2021/06/07 17:07:29 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "myloc.h"

int		g_mlcnt = 0;

int		main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
		return (-1);
	map = get_map(argv[1]);
	if (map == 0)
	{
		perror(strerror(errno));
		//system("leaks so_long");
		printf("g_mlcnt : %d\n", g_mlcnt);
		return (0);
	}
	printf("g_mlcnt : %d\n", g_mlcnt);
	return (0);
}
