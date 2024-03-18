/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:21:00 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/18 15:32:58 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

# define NOT_FOUND -1
static int	skip_quote(char *str, char quote_type)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote_type)
			return (i);
		i++;
	}
	// if (str[i] == '\0')
		// ft_error(SYNTAX_PAIR, quote);
	return (NOT_FOUND);
}

// t_cmd	*parsing_cmd(char *str)
// 추후, split_cmd로직으로 변경예정
char	*parsing_cmd(int tree_type, char *str, int len)
{
	char	*cmd;
	char	*res;

	if (tree_type == OR || tree_type == AND)
		cmd = ft_substr(str, 1, len);
	else
		cmd = ft_substr(str, 0, len);
	// if (root == NULL)
	// 	tree->left = ft_strtrim(cmd, " ");
	// else
	// 	tree->right = ft_strtrim(cmd, " ");
	res = ft_strtrim(cmd, " ");
	free(cmd);
	return (res);
}

int	handle_parenthesis(t_tree **parent_right, char *str)
{
	t_tree	*root;
	int		i;

	i = 1;
	while (str[i] != ')' && str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i += skip_quote(&str[i + 1], str[i]);
		i++;
	}
	// if (str[i] == '\0')
		// ft_error(SYNTAX_PAIR, "()");
	root = init_tree_node();
	root->type = PEREN;
	root->right = lexer(&str[1], i);
	*parent_right = root;
	return (i);
}

t_tree	*handle_operator(t_tree *root, char *str, int start, int i)
{
	t_tree	*tree;
	char	*cmd;
	int		type;

	type = INIT;
	if (str[i] == '|' && str[i + 1] == '|')
		type = OR;
	else if (str[i] == '|')
		type = PIPE;
	else if (str[i] == '&' && str[i + 1] == '&')
		type = AND;
	tree = init_tree_node();
	tree->type = type;
	cmd = ft_substr(str, start, i - start);
	if (root == NULL)
		tree->left = ft_strtrim(cmd, " ");
	else
	{
		root->right = ft_strtrim(cmd, " ");
		tree->left = root;
		tree->child_type[LEFT] = OPERATOR;
	}
	free(cmd);
	return (tree);
}

t_tree	*lexer(char *str, int len)
{
	t_tree	*root;
	int		start;
	int		i;

	root = NULL;
	start = 0;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] == '|' || (str[i] == '&' && str[i + 1] == '&'))//우선무지성 떼는게 맞기떄문에 |는 파이프로 인식하고 &하나는 따로 가능한 연산자가 아니라고 에러해야겠따지원하지않는 연산자입니다
		{
			root = handle_operator(root, str, start, i);
			start = i + 1;
		}
		if (str[i] == '(')
		{
			i += handle_parenthesis(&root, &str[i]);
			start = i + 1;
		}
		// if (str[i] == ')')
			// ft_error(SYNTAX_PAIR, "()");
		if (str[i] == '\'' || str[i] == '\"')
			i += skip_quote(&str[i + 1], str[i]);
		i++;
		if (root != NULL && (root->type == OR || root->type == AND))
			i += 1;
	}
	if (root == NULL)
		root = init_tree_node();
	root->right = parsing_cmd(root->type, &str[start], i);
	return (root);
}
