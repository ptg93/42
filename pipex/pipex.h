#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		**pipe_fd;
	pid_t	*pid;
	char	**cmd;
	char	**envp;
}	t_pipex;

char	*get_path(char *cmd, char **envp);
char	**ft_split(char const *s, char c);

#endif