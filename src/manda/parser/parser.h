/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:43:42 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/19 19:16:04 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# define INIT -1
# define PIPE 0
# define AND 1
# define OR 2
# define PEREN 3

# define LEFT 0
# define RIGHT 1

typedef struct s_tree	t_tree;
typedef struct s_cmd	t_cmd;
typedef struct s_redi	t_redi;
typedef struct s_node	t_node;

# define COMMAND 0
# define OPERATOR 1

typedef struct s_tree
{
	int		type;// ONLY OPERATOR
	bool	child_type[2];
		// OPERATOR -> left&right == t_tree
		// COMMAND -> left&right == t_cmd
	void	*left;// t_tree OR t_cmd
	void	*right;
}			t_tree;

typedef struct s_cmd
{
	char	**cmds; //무사히 open하고 나면, execve하기
	t_redi	*in; //open(); -> error 종료
	t_redi	*out;
}			t_cmd;

# define INPUT 0
# define HEREDOC 1

# define OUTPUT 0
# define APPEND 1

typedef struct s_redi
{
	bool	type;
	char	*file;
	t_redi	*next;
}			t_redi;

t_tree	*parser(char *str, int len);

t_tree	*init_tree_node(int type);
t_tree	*make_parent_tree(t_tree *child, bool direction, int type);
/*
void	tree_init(t_tree *tree);
t_tree	*tree_new_node(void);
t_tree	*tree_make_child(t_tree *parent, t_cmd *content, bool direction);	
t_tree	*tree_make_parent(t_tree *child, int type);

typedef struct s_node
{
	char	*op;
	char	*str;
}			t_node;
*/

#endif