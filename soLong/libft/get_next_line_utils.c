#include "get_next_line.h"
#include <stdio.h>

int	get_len(char *s, int mode, int *found)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		if (found != 0)
			*found = 0;
		return (0);
	}
	while (s[i] != '\0')
	{
		if (mode == 0 && s[i] == '\n')
		{
			if (found != 0)
				*found = 1;
			i++;
			return (i);
		}
		i++;
	}
	if (found != 0)
		*found = 0;
	return (i);
}

char	*reshape_leftovers(char **left, char **next, int len)
{
	int		i;
	char	*temp;

	temp = NULL;
	if ((*left)[len] != '\0')
	{
		temp = malloc((get_len(*left, 1, &i) - len + 1) * sizeof(char));
		if (!temp)
		{
			free(*next);
			*next = NULL;
			free(*left);
			*left = NULL;
			return (NULL);
		}
		i = 0;
		while ((*left)[i + len] != '\0')
		{
			temp[i] = (*left)[i + len];
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}

char	*create_temp_buff(char *buff, char **next, int buff_len, int next_len)
{
	int		i;
	char	*temp;

	temp = malloc((buff_len + next_len + 1) * sizeof(char));
	if (!temp)
	{
		free(*next);
		*next = NULL;
		return (NULL);
	}
	i = 0;
	while (i < next_len)
	{
		temp[i] = (*next)[i];
		i ++;
	}
	while (i - next_len < buff_len)
	{
		temp[i] = buff[i - next_len];
		i ++;
	}
	temp[i] = '\0';
	return (temp);
}

void	bad_bytes_handler(char **left, char *buff, char **next, int bytes)
{
	if (bytes < 0)
	{
		free(*next);
		*next = NULL;
		return ;
	}
	buff[bytes] = '\0';
	if (bytes == 0)
	{
		if (left && *left)
		{
			add_buffer(left, buff, next);
			if (!*next)
				return ;
		}
		return ;
	}
}
