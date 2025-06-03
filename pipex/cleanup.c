#include "pipex.h"

void	error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
