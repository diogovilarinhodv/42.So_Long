#include "get_next_line.h"

static	int	verif_and_init(int fd, char **buf)
{
	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE < 1)
		return (1);
	*buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!(*buf))
		return (1);
	**buf = '\0';
	return (0);
}

static	int	nl_finder(char **storage, int fd, char **ch_finder)
{
	if (storage[fd] != NULL)
	{
		*ch_finder = ft_strchr(storage[fd], '\n');
		if (*ch_finder != NULL)
		{
			(*ch_finder)++;
			if (**ch_finder == '\0')
				*ch_finder = NULL;
			return (1);
		}
	}
	return (0);
}

static	char	*set_both(char **storage, int fd, char **ch_finder, char **buf)
{
	char	*line;
	char	*temp;

	line = NULL;
	if (storage[fd] != NULL)
	{
		if (*ch_finder != NULL)
		{
			line = ft_magical_stuff(storage[fd]);
			temp = ft_strdup(*ch_finder);
			free(storage[fd]);
			storage[fd] = temp;
		}
		else
		{
			line = ft_strdup(storage[fd]);
			free(storage[fd]);
			storage[fd] = NULL;
		}
	}
	free(*buf);
	return (line);
}

static	void	set_storage(char **storage, int fd, char **buf)
{
	char	*temp;

	if (storage[fd] != NULL && *buf != NULL)
	{
		if (*storage[fd] != '\0' && **buf != '\0')
		{
			temp = ft_strjoin(storage[fd], *buf);
			free(storage[fd]);
			storage[fd] = temp;
		}
	}
	else if (*buf != NULL)
	{
		if (**buf != '\0')
			storage[fd] = ft_strdup(*buf);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*storage[1000];
	char		*ch_finder;
	char		*line;
	int			count;

	if (verif_and_init(fd, &buf))
		return (NULL);
	if (nl_finder(&storage[fd], fd, &ch_finder))
		return (set_both(&storage[fd], fd, &ch_finder, &buf));
	while (1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 1)
			break ;
		*(buf + count) = '\0';
		set_storage(&storage[fd], fd, &buf);
		if (nl_finder(&storage[fd], fd, &ch_finder))
			return (set_both(&storage[fd], fd, &ch_finder, &buf));
	}
	line = set_both(&storage[fd], fd, &ch_finder, &buf);
	if (line != NULL)
		return (line);
	return (NULL);
}
