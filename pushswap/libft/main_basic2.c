#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void test_striteri_func(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
}

char test_strmapi_func(unsigned int i, char c)
{
    return (i % 2 == 0 ? ft_toupper(c) : ft_tolower(c));
}

int main(void)
{
    // ft_substr
    char *substr = ft_substr("Hello, World!", 7, 5);
    printf("ft_substr(\"Hello, World!\", 7, 5): %s\n", substr);
    free(substr);

    // ft_strjoin
    char *strjoin = ft_strjoin("Hello, ", "World!");
    printf("ft_strjoin(\"Hello, \", \"World!\"): %s\n", strjoin);
    free(strjoin);

    // ft_strtrim
    char *strtrim = ft_strtrim("  Hello, World!  ", " ");
    printf("ft_strtrim(\"  Hello, World!  \", \" \"): %s\n", strtrim);
    free(strtrim);

    // ft_split
    char **split = ft_split("Hello World 42", ' ');
    printf("ft_split(\"Hello World 42\", ' '):\n");
    for (int i = 0; split[i]; i++)
    {
        printf("- %s\n", split[i]);
        free(split[i]);
    }
    free(split);

    // ft_itoa
    char *itoa = ft_itoa(-12345);
    printf("ft_itoa(-12345): %s\n", itoa);
    free(itoa);

    // ft_strmapi
    char *strmapi = ft_strmapi("hello", test_strmapi_func);
    printf("ft_strmapi(\"hello\", func): %s\n", strmapi);
    free(strmapi);

    // ft_striteri
    char striteri[] = "hello";
    ft_striteri(striteri, test_striteri_func);
    printf("ft_striteri(\"hello\", func): %s\n", striteri);

    // ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        printf("Error opening file for ft_putchar_fd tests.\n");
        return (1);
    }

    ft_putchar_fd('A', fd);
    ft_putstr_fd("Hello, World!", fd);
    ft_putendl_fd("Hello, 42!", fd);
    ft_putnbr_fd(-12345, fd);
    close(fd);

    printf("\nOutputs written to test_output.txt for ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, and ft_putnbr_fd.\n");

    return 0;
}

