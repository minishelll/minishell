/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:14:55 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/17 00:53:59 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*parse tokens recursively*/

#include <stdio.h>
#include <string.h>

void	split_logical_operator(char *line)
{
	int		idx;
	char	state;
	//1. && || 
	//2. " ' () ' "
	idx = strlen(line);

	while (idx >= 0)
	{
		if (idx != 0 && line[idx] == '&' && line[idx - 1] == '&')
		if (line[idx] == '\'' || line[idx] =='\"')
		{
			printf("%s\n",&line[idx]);
			state = line[idx--];
			while (line[idx] != state)
				idx--;
			printf("%s\n",&line[idx+1]);
		}
		if (line[idx] == ')')
		{
			printf("%s\n",&line[idx]);
			while (line[--idx] != '(')
			{
				if (line[idx] == '\'' || line[idx] =='\"')
				{
					printf("%s\n",&line[idx]);
					state = line[idx--];
					while (line[idx] != state)
						idx--;
					printf("%s\n",&line[idx+1]);
				}
			}
			printf("%s\n",&line[idx+1]);
		}
		idx --;
	}
}

int main (){
	t_tree	*parser;
	char *s = "echo \"hihi\" | cat && (echo \"asdf(\" || echo hi | cat)";
	split_logical_operator(s);
}

/*parser main*/
// t_tree	*parser(char *line)
// {
// 	t_tree		*parse_tree;
// 	const int	len = ft_strlen(line);
	

// }
