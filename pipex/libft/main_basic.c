#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	printf("ft_isalpha('A'): %d | isalpha('A'): %d\n", ft_isalpha('A'), isalpha('A'));
    printf("ft_isdigit('1'): %d | isdigit('1'): %d\n", ft_isdigit('1'), isdigit('1'));
    printf("ft_isalnum('A'): %d | isalnum('A'): %d\n", ft_isalnum('A'), isalnum('A'));
    printf("ft_isascii(127): %d | isascii(127): %d\n", ft_isascii(127), isascii(127));
    printf("ft_isprint(32): %d | isprint(32): %d\n", ft_isprint(32), isprint(32));

    printf("\nft_strlen(\"Hello\"): %zu | strlen(\"Hello\"): %zu\n", ft_strlen("Hello"), strlen("Hello"));

    char buffer1[10] = "abcdefghi";
    ft_memset(buffer1, 'X', 3);
    printf("\nft_memset(buffer, 'X', 3): %s\n", buffer1);

    char buffer2[10] = "abcdefghi";
    ft_bzero(buffer2, 5);
    printf("ft_bzero(buffer, 5): %s\n", buffer2 + 5);

    char src[10] = "12345";
    char dest[10] = "abcdefghi";
    ft_memcpy(dest, src, 5);
    printf("ft_memcpy(dest, src, 5): %s\n", dest);

    char overlap[10] = "12345";
    ft_memmove(overlap + 2, overlap, 3);
    printf("ft_memmove(overlap + 2, overlap, 3): %s\n", overlap);

    char dest1[10] = "";
    size_t len1 = ft_strlcpy(dest1, "Hello", sizeof(dest1));
    printf("\nft_strlcpy(dest, \"Hello\", 10): %s | len: %zu\n", dest1, len1);

    char dest2[15] = "Hello";
    size_t len2 = ft_strlcat(dest2, " World", sizeof(dest2));
    printf("ft_strlcat(dest, \" World\", 15): %s | len: %zu\n", dest2, len2);

    printf("\nft_toupper('a'): %c | toupper('a'): %c\n", ft_toupper('a'), toupper('a'));
    printf("ft_tolower('A'): %c | tolower('A'): %c\n", ft_tolower('A'), tolower('A'));

    printf("\nft_strchr(\"Hello\", 'e'): %s | strchr(\"Hello\", 'e'): %s\n", ft_strchr("Hello", 'e'), strchr("Hello", 'e'));
    printf("ft_strrchr(\"Hello\", 'l'): %s | strrchr(\"Hello\", 'l'): %s\n", ft_strrchr("Hello", 'l'), strrchr("Hello", 'l'));

printf("\nft_strncmp(\"Hello\", \"Hell\", 4): %d | strncmp(\"Hello\", \"Hell\", 4): %d\n", ft_strncmp("Hello", "Hell", 4), strncmp("Hello", "Hell", 4));

printf("\nft_memchr(\"abcdef\", 'e', 6): %s | memchr(\"abcdef\", 'e', 6): %s\n", (char *)ft_memchr("abcdef", 'e', 6), (char *)memchr("abcdef", 'e', 6));
    printf("ft_memcmp(\"abc\", \"abd\", 3): %d | memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3), memcmp("abc", "abd", 3));
    printf("ft_strnstr(\"Hello World\", \"World\", 11): %s\n", ft_strnstr("Hello World", "World", 11));

printf("\nft_atoi(\"-42\"): %d | atoi(\"-42\"): %d\n", ft_atoi("-42"), atoi("-42"));

    char *calloc_test = ft_calloc(5, sizeof(char));
    if (calloc_test)
    {
        strcpy(calloc_test, "42");
        printf("\nft_calloc(5, sizeof(char)): %s\n", calloc_test);
        free(calloc_test);
    }

	char *dup_test = ft_strdup("libft");
    printf("\nft_strdup(\"libft\"): %s\n", dup_test);
    free(dup_test);

    return 0;
}
