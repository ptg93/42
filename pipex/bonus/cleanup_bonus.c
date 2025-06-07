#include "pipex_bonus.h"

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

void	free_pipe_fd(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->num_pipes)
		free(d->pipe_fd[i++]);
	free(d->pipe_fd);
}

void	wait_and_cleanup(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->num_cmd)
		waitpid(d->pid[i++], NULL, 0);
	close(d->infile);
	close(d->outfile);
	close_all_pipes(d);
	free_pipe_fd(d);
	free(d->pid);
}
