#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex data;
	char **cmd1;
	char **cmd2;

	if (argc != 5)
		return (1);
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile < 0)
		return (1);
	data.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data.outfile < 0)
	{
		close(data.infile);
		return (1);
	}
	if (pipe(data.pipe_fd) == -1)
	{
		close(data.infile);
		close(data.outfile);
		return (1);
	}
	data.pid1 = fork();
	if (data.pid1 < 0)
		return (1);
	if (data.pid1 == 0)
	{
		dup2(data.infile, STDIN_FILENO);
		dup2(data.pipe_fd[1], STDOUT_FILENO);
		close(data.pipe_fd[0]);
		close(data.infile);
		close(data.outfile);
		cmd1 = ft_split(argv[2], ' ');
		execve(get_path(cmd1[0], envp), cmd1, envp);
		exit(1);
	}
	data.pid2 = fork();
	if (data.pid2 < 0)
		return (1);
	if (data.pid2 == 0)
	{
		dup2(data.pipe_fd[0], STDIN_FILENO);
		dup2(data.outfile, STDOUT_FILENO);
		close(data.pipe_fd[1]);
		close(data.infile);
		close(data.outfile);
		cmd2 = ft_split(argv[3], ' ');
		execve(get_path(cmd2[0], envp), cmd2, envp);
		exit(1);
	}
	close(data.pipe_fd[0]);
    close(data.pipe_fd[1]);
    waitpid(data.pid1, NULL, 0);
    waitpid(data.pid2, NULL, 0);

    return (0);
}

