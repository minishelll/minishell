/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:43:42 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/18 14:21:35 by taerakim         ###   ########.fr       */
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

# define COMMAND 0
# define OPERATOR 1

# define LEFT 0
# define RIGHT 1

typedef struct s_tree	t_tree;
typedef struct s_cmd	t_cmd;
typedef struct s_redi	t_redi;
typedef struct s_node	t_node;

typedef struct s_tree
{
	int		type;
	bool	child_type[2];
	void	*left;
	void	*right;
}			t_tree;

typedef struct s_cmd
{
	// char	**cmds;
	char	*orgin_cmd;
	t_redi	*in;
	t_redi	*out;
	t_cmd	*next;
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

t_tree	*lexer(char *str, int len);

t_tree	*init_tree_node(void);
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