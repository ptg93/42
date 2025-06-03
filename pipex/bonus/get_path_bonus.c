#include "pipex_bonus.h"

static char	*join_path(char **dir, const char *cmd)
{
	size_t	len;
	char	*full;
	int		i;

	i = 0;
	while (dir[i])
	{
		len = ft_strlen(dir[i]) + ft_strlen(cmd) + 2;
		full = malloc(len);
		if (!full)
			return (NULL);
		ft_strlcpy(full, dir[i], len);
		ft_strlcat(full, "/", len);
		ft_strlcat(full, cmd, len);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	error_message("join_path");
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			error_message("command not found");
	}
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		error_message("PATH not found in environment variables");
	path_env = *envp + 5;
	paths = ft_split(path_env, ':');
	if (!paths)
		error_message("ft_split");
	full_path = join_path(paths, cmd);
	ft_free_split(paths);
	if (!full_path)
		error_message("command not found");
	return (full_path);
}
