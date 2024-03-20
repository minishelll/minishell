/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ver2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:38:15 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/20 11:09:40 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// #include "ft_error.h"
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


// t_cmd	*parsing_cmd(char *str, int len)
char	*parsing_cmd(char *str, int start, int i)
{
	char	*cmd;
	char	*tmp;

	tmp = ft_substr(str, start, i - start);
	cmd = ft_strtrim(tmp, " ");
	free(tmp);

	return (cmd);
}
	//redirection 분리
	
	// ??? 여기서 expand해야되는지는 모루겠떠

void	handle_pipe(t_tree **root, char *str, int start, int i)
{
	t_tree	*new;

	new = init_tree_node(PIPE);
	if (*root == NULL)
		new->left = parsing_cmd(str, start, i);
	else
	{
		(*root)->right = parsing_cmd(str, start, i);
		new->left = *root;
		new->child_type[LEFT] = OPERATOR;
	}
	*root = new;
}

t_tree	*pipe_op_parser(char *str, int len)
{
	t_tree	*root;
	int		start;
	int		i;

	root = NULL;
	start = 0;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] == '|')
		{
			handle_pipe(&root, str, start, i);
			start = i + 1;
		}
		if (str[i] == '(' || str[i] == ')')
			str[i] = ' ';
		i++;
	}
	if (root == NULL)
		root = init_tree_node(INIT);
	root->right = parsing_cmd(str, start, i);
	return (root);
}
	//pipe기준으로 parsing_cmd()
	//이 str에 포함된 괄호는 space로 대체되어 동작

	//파이프가 발견되지 않으면
	//type == INIT 인채로, left에 붙혀서 return


// int	handle_parenthesis(t_tree **root, char *str, int start, int i)
// {
// 	t_tree	*new;
// 	int		pair;

// 	pair = i;
// 	while (str[pair] != ')' && str[pair] != '\0')
// 		pair++;
// 	if (str[pair] == '\0')
// 		ft_error(SYNTEX_ERROR, "(");
// 	if ((*root)->type == AND || (*root)->type == OR)
// 		new = parser(&str[i + 1], i - pair - 1);//아이러면 parser에서 처리해준것도 할줄 알아야하나자..

// 	else
// 	{
// 		str[i] = ' ';
// 		str[pair] = ' ';
// 	}
// 	return (pair - i);
// }


void	handle_direction(t_tree *target, t_tree *add, bool direction)
{
	if (direction == LEFT)
	{
		if (add->type == INIT)
		{
			target->left = add->right;
			free(add);
		}
		else
		{
			target->left = add;
			target->child_type[LEFT] = OPERATOR;
		}
		return ;
	}
	if (add->type == INIT)
	{
		target->right = add->right;
		free(add);
	}
	else
	{
		target->right = add;
		target->child_type[RIGHT] = OPERATOR;
	}
}

void	handle_logical(t_tree **root, char *str, int start, int i)
{
	t_tree	*new;
	t_tree	*tmp;
	int		type;

	if (str[i] == '&' && str[i] == '&')
		type = AND;
	else
		type = OR;
	new = init_tree_node(type);
	tmp = pipe_op_parser(&str[start], i - start);
	if (*root != NULL)
		handle_direction(*root, tmp, RIGHT);
	else
		handle_direction(new, tmp, LEFT);
	if (*root != NULL)
	{
		new->left = *root;
		new->child_type[LEFT] = OPERATOR;
	}
	*root = new;
}

int	logic_op_parser(t_tree **root, char *str, int len)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if ((str[i] == '|' && str[i + 1] == '|') \
		|| (str[i] == '&' && str[i + 1] == '&'))
		{
			handle_logical(root, str, start, i);
			start = i + 2;
		}
		// if (str[i] == '(')
		// {
		// 	i += handle_parenthesis(root, &str[i], start, i);
		// 	start = i + 1;
		// }
		// if (str[i] == ')')
		// 	ft_error(SYNTEX_ERROR, "(");
		if (str[i] == '\'' || str[i] == '\"')
			i += skip_quote(&str[i + 1], str[i]);
		i++;
	}
	return (start);
}
	//while문 돌며 논리연산자 기준으로
	//앞은 seperate_pipe()반환된거 왼쪽에 붙히고
	//뒤는 마저 while문돌기
	//마지막을 오른쪽에 붙히기

	//괄호
		//0. 탐색하고 적절한 호출 분리된 함수
		//1. 앞뒤로 연산자외 토큰이 있는지 검사
			//SYNTAX ERROR -> renewal된 start와 (발견시점 사이로 space가 아닌 무언가가 있다면
		//2. 직전이 논리연산자가 아닌 pipe면 ... 평소처럼 동작...
			//보너스 요구가 논리연산자에서 괄호의 의미를 요한다고 생각하기도 하고
			//관찰했을때 없을떄랑 동일하게작동하는 것 같기 때문에
		//3. 논리연산자라면 오른쪽에 붙힐ㄷ텐데... 
		//??? 이러면 그냥 2,3번은 이 함수 다시 호출하면 되겠따.
		//기본적으로 오른쪽으로 붙힌다.	
	//괄호내에 논리 연산자가 없으면 -> seperate_pipe()에서 space로 대체 후 진행

	//발견되지않으면 그것만 또는 마지막도 pipe분리 호출

t_tree	*parser(char *str, int len)// ft_strlen(str);해서 들어오기
{
	t_tree		*root;
	t_tree		*tmp;
	int			last;

	root = NULL;
	last = logic_op_parser(&root, str, len);
	if (root == NULL)
		root = pipe_op_parser(&str[last], len - last);
	else
	{
		tmp = pipe_op_parser(&str[last], len - last);
		handle_direction(root, tmp, RIGHT);
	}
	return (root);
	//1. 검사 함수 모자른거!
		//type == INIT (연산자 없는 상태)가 아닌이상
		//한쪽의 데이터가 빈문자열이어선 안되는데
			//<= strtrim되고나면 토큰이없는 케이스는 빈문자열이 된다..
			// 이거 parsing_cmd()에서 처리해야할지도
	//2. type == PEREN일때
		//왼쪽에 남아있는거...
		// ??? 이거 여기서 검사할때 처리할지... 발견즉시는 어렵겠찌..?
}

// ??? 아 근데 기본적으로 
