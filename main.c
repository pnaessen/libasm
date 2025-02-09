/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:25:22 by pnaessen          #+#    #+#             */
/*   Updated: 2025/02/09 16:31:10 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

int main()
{
    char *test_str = "Hello, World!";
    printf("ft_strlen: %ld\n", ft_strlen(test_str));

    char dest[50];
    printf("ft_strcpy: %s\n", ft_strcpy(dest, test_str));

    char *str1 = "Hello, ";
    char *str2 = "Hello, ";
    char *str3 = "World!";
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str2));
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str3));

    printf("ft_write test:\n");
    ft_write(1, "This is a test string\n", 21);

    size_t ret = ft_write(-1, "test", 4);
    printf("ft_write error return: %zd, errno: %d\n", ret, errno);

    char buf[50];
    printf("ft_read test:\n");
    size_t read_ret = ft_read(0, buf, 49);
    if (read_ret > 0)
    {
        buf[read_ret] = '\0';
        printf("ft_read: %s\n", buf);
    }

    char *dup = ft_strdup(test_str);
    if (dup)
    {
        printf("ft_strdup: %s\n", dup);
        free(dup);
    }
    
    return (0);
}

// pour compil gcc -o test main.c -L. -lasm