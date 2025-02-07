/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/02/07 14:32:12 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);

int	main(int argc, char *argv[])
{
	char	*test_str;
	size_t	my_len;
	//size_t	len;

	test_str = argv[1];
	if (argc == 1)
		return (1);
	my_len = ft_strlen(test_str);
//	len = strlen(test_str);
	printf("ft_strlen result: %zu\n", my_len);
	//printf("libc strlen result: %zu\n", len);
	return (0);
}

// ft_strlen result: 91169
// ./len   0.00s user 0.00s system 81% cpu 0.002 total

// libc strlen result: 91169
// ./a.out   0.00s user 0.00s system 80% cpu 0.001 total