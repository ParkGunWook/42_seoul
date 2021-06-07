/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:37:17 by gpark             #+#    #+#             */
/*   Updated: 2021/06/07 13:44:04 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLOC_H
# define MYLOC_H

# include <stdlib.h>

extern int g_mlcnt;

int		my_aloc(void **ptr, size_t size);
void	my_free(void **ptr);

#endif
