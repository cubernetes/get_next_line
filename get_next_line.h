/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tosuman <timo42@proton.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:27:48 by tosuman           #+#    #+#             */
/*   Updated: 2023/09/12 01:03:33 by tosuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <sys/types.h>

typedef struct s_all
{
	char	*prv[OPEN_MAX];
	char	*buf;
	ssize_t	bread;
	int		i;
	int		j;
	int		len;
}			t_gnl_vars;

char	*get_next_line(int fd);

#endif
