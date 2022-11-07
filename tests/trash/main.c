#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
int main()
{
	size_t fd;
	
	fd = open("file.txt", O_RDWR);
	//write(fd, "DIO BELLO", 9);
	for (int i = 0; i < 6; i++)
		printf("%s\n", get_next_line(fd));
	close(fd);
}
