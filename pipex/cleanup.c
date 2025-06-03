#include "pipex_bonus.h"

void	error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
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
	{
		waitpid(d->pid[i], NULL, 0);
		i++;
	}
	close(d->infile);
	close(d->outfile);
	close_all_pipes(d);
	i = 0;
	while (i < d->num_pipes)
		free(d->pipe_fd[i++]);
	free(d->pipe_fd);
	free(d->pid);
}
