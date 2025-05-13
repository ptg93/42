#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
    char	*line;

	if (argc == 1)
	{
		fd = 0;
		printf("Reading from stdin (write and press Enter to see the result, CTRL+D to exit):\n");
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error opening file");
			return (1);
		}
	}
	else
	{
		printf("Use: %s [file]\n", argv[0]);
		return (1);
	}

	while ((line = get_next_line(fd)))
	{
		printf("Line: %s", line);
		free(line);
	}
	if (fd > 0)
		close(fd);

	return (0);
}
