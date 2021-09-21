#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	inc;

	inc = 0;
	while (*(s + inc) != '\0')
		inc++;
	return ((size_t)inc);
}

char	*ft_strchr(const char *s, int c)
{
	int	inc;

	inc = 0;
	while (*(s + inc) != '\0')
	{
		if (*(s + inc) == (char)c)
			break ;
		inc++;
	}
	if (*(s + inc) != '\0' || c == '\0')
		return ((char *)(s + inc));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		cnt;

	p = (char *)malloc(ft_strlen(s) + 1);
	cnt = 0;
	if (p == NULL)
		return (NULL);
	while (*(s + cnt) != '\0')
	{
		*(p + cnt) = *(s + cnt);
		cnt++;
	}
	*(p + cnt) = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cnt;
	int		inc;
	char	*p;

	inc = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	while (*(s1 + inc) != '\0')
	{
		*(p + inc) = *(s1 + inc);
		inc++;
	}
	cnt = 0;
	while (*(s2 + cnt) != '\0')
	{
		*(p + inc) = *(s2 + cnt);
		cnt++;
		inc++;
	}
	*(p + inc) = '\0';
	return (p);
}

char	*ft_magical_stuff(char const *storage)
{
	char	*p;
	int		inc;
	int		inc_max;

	inc = 0;
	inc_max = 0;
	while (*(storage + inc_max) != '\n' && *(storage + inc_max) != '\0')
		inc_max++;
	p = malloc((sizeof(char) * inc_max) + 2);
	while (inc < inc_max)
	{
		*(p + inc) = *(storage + inc);
		inc++;
	}
	*(p + inc) = '\n';
	*(p + (inc + 1)) = '\0';
	return (p);
}
