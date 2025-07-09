/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptraba-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:07:25 by ptraba-d          #+#    #+#             */
/*   Updated: 2025/06/28 10:07:27 by ptraba-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

void	error_message(const char *msg);
char	*get_path(char *cmd, char **envp);
char	**ft_split(char const *s, char c);
char	**ft_split_quotes(char *str);
void	ft_free_split(char **arr);
void	run_command(t_pipex *d, char *arg, char **envp, int idx);

#endif
