#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../get_next_line.h"

int main()
{
	size_t fd;
	char *s;

        fd = open("get_next_line.h", O_RDWR);
        for(int i = 0; i < 40; i++)
	{	
		s = get_next_line(fd);
		if (!s)
			return (0);
                printf("'%s'\n\n", s);
		free(s);
	}
	free(s);
        close(fd);
}
