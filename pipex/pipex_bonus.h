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
void	execute_command(t_pipex *d, char **argv, int idx);
char    *get_path(char *cmd, char **envp);

#endif