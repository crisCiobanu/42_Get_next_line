
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 42
#endif

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);