#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		**pipe_fd;
	pid_t	*pid;
	int		num_cmd;
	int		num_pipes;
	char	**envp;
}			t_pipex;

void	error_message(const char *msg);
char	*get_path(char *cmd, char **envp);
char	**ft_split(char const *s, char c);
void	run_commands(t_pipex *d, char **argv);
void	close_all_pipes(t_pipex *d);
void	wait_and_cleanup(t_pipex *d);
void	free_pipe_fd(t_pipex *d);
void	ft_free_split(char **arr);

#endif