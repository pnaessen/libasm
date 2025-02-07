/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:19 by pnaessen          #+#    #+#             */
/*   Updated: 2025/02/07 14:15:07 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);

int	main(int argc, char *argv[])
{
	char	*test_str;
	//size_t	my_len;
	size_t	len;

	test_str = argv[1];
	if (argc == 1)
		return (1);
	//my_len = ft_strlen(test_str);
	len = strlen(test_str);
	//printf("ft_strlen result: %zu\n", my_len);
	printf("libc strlen result: %zu\n", len);
	return (0);
}