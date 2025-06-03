#include "pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>

static char *join_path(const char *dir, const char *cmd)
{
    size_t len = ft_strlen(dir) + ft_strlen(cmd) + 2;
    char *full = malloc(len);
    if (!full) return NULL;
    ft_strlcpy(full, dir, len);
    ft_strlcat(full, "/", len);
    ft_strlcat(full, cmd, len);
    return full;
}

char *get_path(char *cmd, char **envp)
{
    char **paths;
    char *path_env;
    char *full_path;
    int i;

    while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
        envp++;
    if (!*envp)
        return NULL; 
    path_env = *envp + 5;
    paths = ft_split(path_env, ':');
    if (!paths)
        return NULL;
    i = 0;
    while (paths[i])
    {
        full_path = join_path(paths[i], cmd);
        if (!full_path)
            break;
        if (access(full_path, X_OK) == 0)
        {
            ft_free_split(paths);
            return full_path;
        }
        free(full_path);
        i++;
    }
    ft_free_split(paths);
    return NULL;
}