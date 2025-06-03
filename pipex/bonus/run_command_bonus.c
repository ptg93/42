#include "pipex_bonus.h"

static void	execute_command(t_pipex *d, char **argv, int idx)
{
	char	**cmd;

	if (idx == 0)
	{
		dup2(d->infile, STDIN_FILENO);
		dup2(d->pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (idx == d->num_cmd - 1)
	{
		dup2(d->pipe_fd[idx - 1][0], STDIN_FILENO);
		dup2(d->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(d->pipe_fd[idx - 1][0], STDIN_FILENO);
		dup2(d->pipe_fd[idx][1], STDOUT_FILENO);
	}
	close(d->infile);
	close(d->outfile);
	close_all_pipes(d);
	cmd = ft_split(argv[idx + 2], ' ');
	execve(get_path(cmd[0], d->envp), cmd, d->envp);
	ft_free_split(cmd);
	error_message("execve");
}

void	run_commands(t_pipex *d, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->num_cmd)
	{
		d->pid[i] = fork();
		if (d->pid[i] < 0)
			error_message("fork");
		if (d->pid[i] == 0)
			execute_command(d, argv, i);
		i++;
	}
	j = 0;
	while (j < d->num_pipes)
	{
		close(d->pipe_fd[j][0]);
		close(d->pipe_fd[j][1]);
		j++;
	}
}
