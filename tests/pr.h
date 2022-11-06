#ifndef PR_H
#define PR_H
#include <unistd.h>
#include <stdlib.h>
typedef struct s_buff
{
int	i;
	char	*buf;
	int	dim;
	int	finish;
}	t_buff;

char	*get_next_line(int fd);
void    *ft_realloc(void *ptr, size_t plus);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t  ft_strlen(const char *s);

#endif
