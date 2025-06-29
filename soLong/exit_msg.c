#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>  // For perror
#include <unistd.h> // For close
#include <stdlib.h> // For exit
#include <string.h> // For strerror
void	exit_msg(const char *msg)
{
    if (msg)
        perror(msg);
    else
        perror("An error occurred");
    exit(EXIT_FAILURE);
}