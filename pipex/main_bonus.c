/* pipex_bonus.c */
#include "pipex_bonus.h"

static void	close_all_pipes(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->num_pipes)
	{
		close(d->pipe_fd[i][0]);
		close(d->pipe_fd[i][1]);
		i++;
	}
}

static void	wait_and_cleanup(t_pipex *d)
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

static void	create_pipes(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->num_pipes)
	{
		if (pipe(d->pipe_fd[i]) == -1)
			error_message("pipe");
		i++;
	}
}

static void	allocate_data(t_pipex *d)
{
	int	i;

	d->pipe_fd = malloc(sizeof(int *) * d->num_pipes);
	if (!d->pipe_fd)
		error_message("malloc");
	i = 0;
	while (i < d->num_pipes)
	{
		d->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!d->pipe_fd[i])
			error_message("malloc");
		i++;
	}
	d->pid = malloc(sizeof(pid_t) * d->num_cmd);
	if (!d->pid)
		error_message("malloc");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		i;

	if (argc < 5)
		return (1);
	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[argc - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data.infile < 0 || data.outfile < 0)
		error_message("open");
	data.num_cmd   = argc - 3;
	data.num_pipes = data.num_cmd - 1;
	data.envp      = envp;
	allocate_data(&data);
	create_pipes(&data);
	i = 0;
	while (i < data.num_cmd)
	{
		data.pid[i] = fork();
		if (data.pid[i] < 0)
			error_message("fork");
		if (data.pid[i] == 0)
			execute_command(&data, argv, i);
		i++;
	}
	wait_and_cleanup(&data);
	return (0);
}
