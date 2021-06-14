/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:26:37 by gpark             #+#    #+#             */
/*   Updated: 2021/06/14 16:38:19 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char	**argv;

	argv = malloc(sizeof(char*) * 3);
	argv[0] = "ls";
	argv[1] = "-l";
	printf("%c %c %d\n", argv[0][0], argv[0][1], argv[0][2]);
	argv[2] = NULL;
	execve("/bin/ls", argv, 0);
	return (0);
}