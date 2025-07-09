/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:07:47 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/06/28 10:07:50 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split_quotes(arg);
	if (!cmd || !cmd[0])
		error_message("invalid command");
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_free_split(cmd);
		error_message("command not found");
	}
	execve(path, cmd, envp);
	ft_free_split(cmd);
	free(path);
	error_message("execve");
}

void	run_command(t_pipex *d, char *arg, char **envp, int idx)
{
	if (idx == 0)
	{
		dup2(d->infile, STDIN_FILENO);
		dup2(d->pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(d->pipe_fd[0], STDIN_FILENO);
		dup2(d->outfile, STDOUT_FILENO);
	}
	close(d->pipe_fd[0]);
	close(d->pipe_fd[1]);
	close(d->infile);
	close(d->outfile);
	execute_command(arg, envp);
}
