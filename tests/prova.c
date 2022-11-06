#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pr.h"
#include "../get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

void ft_scopy(char *dst, char *src)
{
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char *get_line(int fd)
{
	static t_buff roba;
	char *ptr;
	int j;
	int tmp;

	while (!(roba.finish))
	{
		if (!(roba.buf))
		{
			roba.buf = malloc(BUFFER_SIZE + 1);
				if (!roba.buf)
					return (NULL);
			(roba.buf)[BUFFER_SIZE] = '\0';//to bzero
			roba.dim = BUFFER_SIZE;
		}
		else if (roba.buf[(roba.dim) - BUFFER_SIZE] == '\0')
		{
			ptr = malloc(roba.dim + BUFFER_SIZE + 1);
							//ft_memmove(ptr, porco.buf, porco.dim + 5);
			ft_scopy(ptr, roba.buf);
			free(roba.buf);
			roba.buf = ptr;
		}
		j = 0;///
		while (((roba.buf)[(roba.i) + j]) && (roba.buf)[(roba.i) + j] != '\n')
			j++;
		j += ((roba.buf)[(roba.i) + j] == '\n');
		if ((roba.buf)[(roba.i) + j - 1] == '\n' && j != 0)
		{
			tmp = roba.i;
			roba.i += j;
			return (ft_substr(roba.buf, tmp, j));
		}///
		tmp = read(fd, &((roba.buf)[(roba.dim) - BUFFER_SIZE]), BUFFER_SIZE);
			if (tmp == -1)
				return (NULL);
			if (!tmp && !roba.finish)
			{
				roba.finish = 1;
				return (ft_substr(roba.buf, tmp, j));
			}
		(roba.dim) += BUFFER_SIZE;
		roba.buf[(roba.dim) + 1] = '\0';
							//printf("pb = \n{%s}\n", porco.buf);
	}
	return (NULL);
}

int main()
{
	size_t fd;
	
	fd = open("pr.h", O_RDWR);
	for(int i = 0; i < 20; i++)
		printf("'%s'\n\n", get_line(fd));
	close(fd);
}
