#include "pipex.h"

static void	open_files(t_pipex *d, char *in, char *out)
{
	d->infile = open(in, O_RDONLY);
	if (d->infile < 0)
		error_message("infile");
	d->outfile = open(out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (d->outfile < 0)
		error_message("outfile");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		error_message("Usage: ./pipex infile cmd1 cmd2 outfile");
	open_files(&data, argv[1], argv[4]);
	if (pipe(data.pipe_fd) == -1)
		error_message("pipe");
	data.pid1 = fork();
	if (data.pid1 < 0)
		error_message("fork");
	if (data.pid1 == 0)
		run_command(&data, argv[2], envp, 0);
	data.pid2 = fork();
	if (data.pid2 < 0)
		error_message("fork");
	if (data.pid2 == 0)
		run_command(&data, argv[3], envp, 1);
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	return (0);
}
