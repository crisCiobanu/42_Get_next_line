#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lengths1;
	int		lengths2;
	int		i;
	int		j;
	char	*result;

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
	return (result);
}

char	*ft_strdup(const char *src)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	result = malloc(sizeof(*s) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			result[i] = s[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}

