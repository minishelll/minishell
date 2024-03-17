/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:41:01 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/17 10:08:55 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	// t_tree	*root;
	char	*input;

	if (argc != 1 && argv[1] != NULL)
		return (0);
		// ft_error(BASH_ARGU_ERROR , argv[1]);
	while (1)
	{
		input = readline("minishell$ ");
		if (ft_strncmp(input, "EOF", 4) == 0)
			return (0);
		printf("input: %s\n", input);
		// root = parser(input);
	}
	(void)envp;
}
