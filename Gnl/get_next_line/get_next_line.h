/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:51 by gpark             #+#    #+#             */
/*   Updated: 2021/05/15 20:04:52 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE 16

# define ERROR -1
# define READ_DONE 0
# define SAVE_PART 1
# define GET_ALL 2

# define READ 0
# define ENDL 1
# define SAVE 2

# include <unistd.h>
# include <stdlib.h>

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
size_t		endl_is_in_string(char *buff, size_t num_read);
size_t		get_flag(size_t num_read, size_t endl_idx);

# endif
