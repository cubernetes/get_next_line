/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tosuman <timo42@proton.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:19:18 by tosuman           #+#    #+#             */
/*   Updated: 2023/09/12 02:35:52 by tosuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_gnl_vars	x;

	while (x.prv[fd] && x.prv[fd][x.len])
		++x.len;
	x.buf = malloc(x.len + BUFFER_SIZE + 1);
	x.bread = read(fd, x.buf + x.len, BUFFER_SIZE);
	if (x.bread < 0)
		return (free(x.buf), free(x.prv[fd]), x.len = 0, x.prv[fd] = NULL);
	(free(NULL), x.buf[x.len + x.bread] = 0, x.i = x.len, x.j = -1);
	while (--x.len >= 0)
		x.buf[x.len] = x.prv[fd][x.len];
	while (x.buf[++x.len] && x.buf[x.len] != '\n')
		;
	if (!x.buf[x.len] && x.bread == 0 && (free(x.buf), 1))
		return (x.buf = x.prv[fd], x.prv[fd] = NULL, x.len = 0, x.buf);
	if (!x.buf[x.len] && x.bread == BUFFER_SIZE && (free(x.prv[fd]), 1))
		return (x.prv[fd] = x.buf, x.len = 0, get_next_line(fd));
	if (!x.buf[x.len] || (x.buf[x.len] == '\n' && !x.buf[x.len + 1]))
		return (free(x.prv[fd]), x.prv[fd] = NULL, x.len = 0, x.buf);
	(free(x.prv[fd]), x.prv[fd] = malloc(sizeof(char) * (x.i + x.bread + 1)));
	if (!x.prv[fd])
		return (free(x.buf), free(x.prv[fd]), x.len = 0, x.prv[fd] = NULL);
	while (x.buf[x.len + 1 + ++x.j] || !x.prv[fd])
		x.prv[fd][x.j] = x.buf[x.len + 1 + x.j];
	return (x.prv[fd][x.j] = 0, x.buf[x.len + 1] = 0, x.len = 0, x.buf);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		max_iter;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	max_iter = 100;
	while ((line = get_next_line(fd)) && (max_iter-- > 0))
		(printf("<%s>", line), fflush(stdout), free(line));
	close(fd);
}
*/
