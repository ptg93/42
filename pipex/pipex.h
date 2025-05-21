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
    int     infile;
    int     outfile;
    int     *pipe_fd[2];
    pid_t   *pid;
    char    **cmd;
    char    **envp;
}           t_pipex;

void    error_message(const char *message);
void    execute_command(t_pipex *data, char **argv, int index);
char    *get_path(char *cmd, char **envp);

#endif
