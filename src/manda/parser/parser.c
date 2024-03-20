/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:30:06 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/19 09:18:49 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	**logic_op_parser(char *line)
{
	const int	len = ft_strlen(line);
	int			idx;
	t_list		*list;
	int			word_start;

	word_start = 0;
	idx = -1;
	while (++idx < len)
	{
		if (line[idx] == '&')
		{
			if (line[idx + 1] == '&')
				ft_lstadd_back(list, (ft_substr(line, word_start++, idx++ - 1), "&&"));
			else
				ft_lstadd_back(list, (ft_substr(line, word_start, idx - 1), "&"));
			word_start++;
		}
		else if (line[idx] == '|' && line[idx + 1] == '|')
		{
			ft_lstadd_back(list, (ft_substr(line, word_start, idx++ - 1), "||"));
			word_start += 2;
		}
		else if (line[idx] == '\'' || line[idx] == '\"')
			idx = find_quote(line, idx, line[idx]);
		else if (line[idx] == '(')
		{
			while (line[++idx] != ')')
			{
				if (line[idx] == '\'' || line[idx] == '\"')
					idx = find_quote(line, idx, line[idx]);
			}
		}
	}
	ft_lstadd_back(list, (ft_substr(line, word_start, len - 1), "\0"));
	return (&list);
}

void	parser(char *line)
{
	t_list	**list;
	t_tree	**tree;

	list = logical_op_parser(line);
	tree = pipe_parser(list);
}

int	find_quote(char *line, int start, char type)
{
	const int	len = ft_strlen(line);
	int			idx;

	idx = start;
	while (line[idx] != type && idx < len)
		idx++;
	return (idx);
}

int main(){
	char *s = "echo \"asdf(\" | cat || (echo \"qwer\" && echo 'zxcv')   ";
	parser(s);
}