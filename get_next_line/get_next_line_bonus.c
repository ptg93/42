#include "get_next_line_bonus.h"
#include <stdio.h>

void	add_leftovers(char **left, char **next)
{
	int		i;
	int		len;
	char	*temp;

	len = get_len(*left, 0, &i);
	*next = malloc((len + 1) * sizeof(char));
	if (!*next)
	{
		free(*left);
		*left = NULL;
		return ;
	}
	i = 0;
	while (i < len)
	{
		(*next)[i] = (*left)[i];
		i ++;
	}
	(*next)[i] = '\0';
	temp = reshape_leftovers(left, next, len);
	free(*left);
	*left = temp;
}

void	populate_leftovers(char **left, char *buff, char **next, int buff_len)
{
	int	i;

	*left = malloc((get_len(buff, 1, &i) - buff_len + 1) * sizeof(char));
	if (!*left)
	{
		free(*next);
		*next = NULL;
		*left = NULL;
		return ;
	}
	i = 0;
	while (buff[i + buff_len] != '\0')
	{
		(*left)[i] = buff[i + buff_len];
		i++;
	}
	(*left)[i] = '\0';
}

void	add_buffer(char **left, char *buff, char **next)
{
	int		buff_len;
	int		next_len;
	int		dummy;
	char	*temp;

	buff_len = get_len(buff, 0, &dummy);
	next_len = get_len(*next, 1, &dummy);
	temp = create_temp_buff(buff, next, buff_len, next_len);
	if (!temp)
		return ;
	free(*next);
	*next = temp;
	if (buff[buff_len] != '\0')
	{
		populate_leftovers(left, buff, next, buff_len);
		if (!*left)
			return ;
	}
}

void	read_next(char **left, char *buff, char **next, int fd)
{
	int	bytes_read;
	int	len;
	int	found;

	while (1)
	{
		if (*left && **left)
		{
			add_leftovers(left, next);
			len = get_len(*next, 0, &found);
			if (!*next || found == 1)
				return ;
		}
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			bad_bytes_handler(left, buff, next, bytes_read);
			return ;
		}
		buff[bytes_read] = '\0';
		add_buffer(left, buff, next);
		len = get_len(*next, 0, &found);
		if (!*next || (len > 0 && found == 1))
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*leftovers[1024];
	char		*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		if (leftovers[fd])
		{
			free(leftovers[fd]);
			leftovers[fd] = NULL;
		}
		return (NULL);
	}
	next_line = NULL;
	read_next(&leftovers[fd], buffer, &next_line, fd);
	if (!next_line && leftovers[fd])
	{
		free(leftovers[fd]);
		leftovers[fd] = NULL;
	}
	free(buffer);
	return (next_line);
}
