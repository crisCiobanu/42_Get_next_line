#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;
    
    if (!s)
        return (0);
    length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*chr;
	char	tc;

	 if (!s)
        return (NULL);
    
    tc = (char) c;
	chr = (char *) s;
	  
    if (c == '\0')
		return (chr + ft_strlen(chr));
	count = 0;
	while (*(chr + count))
	{
		if (*(chr + count) == tc)
			return (chr + count);
		count++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lengths1;
	int		lengths2;
	int		i;
	int		j;
	char	*result;

    if (!s1)
    {
        s1 = malloc(sizeof(*s1));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    i = 0;
	lengths1 = ft_strlen(s1);
	lengths2 = ft_strlen(s2);

	result = malloc(sizeof(*s1) * (lengths1 + lengths2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';
    free(s1);
	return (result);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*tmp;

	length = 0;
	while (src[length])
		length++;
	tmp = malloc(sizeof(*tmp) * length + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';

	return (tmp);
}

