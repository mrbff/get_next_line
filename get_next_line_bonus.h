/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:59:15 by mabaffo           #+#    #+#             */
/*   Updated: 2022/11/11 16:01:12 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buff
{
	size_t	i;
	char	*buf;
	size_t	dim;
	int		finish;
}	t_buff;

char	*get_next_line(int fd);
void	ft_realloc(char **buf, size_t *dim);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_scopy(char *dst, char *src);
size_t	ft_strlen(const char *s);
int		ft_line(char *buf, size_t *i, long long int *j);

#endif
