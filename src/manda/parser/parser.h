/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:43:42 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/20 14:42:33 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* ******************************* INCLUDE ********************************** */
#include <stdio.h>
# include <stdbool.h>
# include "libft.h"

/* ******************************** STRUCTS ********************************* */
typedef struct s_tree	t_tree;
typedef struct s_cmd	t_cmd;
typedef struct s_redi	t_redi;

/* TREE */
typedef struct s_tree
{
	int		type;
	bool	child_type[2];
	void	*left;
	void	*right;
}			t_tree;

/* COMMAND */
typedef struct s_cmd
{
	char	**cmds;
	t_redi	*in;
	t_redi	*out;
}			t_cmd;

/* REDIRECTION */
typedef struct s_redi
{
	bool	type;
	char	*file;
	t_redi	*next;
}			t_redi;

/* ******************************** MACRO *********************************** */
/* t_tree, TYPE  */
# define INIT -1
# define PIPE 0
# define AND 1
# define OR 2
# define PEREN 3
/* t_tree, CHILD_TYPE  */
# define COMMAND 0
# define OPERATOR 1
/* t_tree, DIRECTION  */
# define LEFT 0
# define RIGHT 1

/* t_redi, IN_TYPE */
# define INPUT 0
# define HEREDOC 1
/* t_redi, OUT_TYPE */
# define OUTPUT 0
# define APPEND 1

/* UTIL */
# define NOT_FOUND -1

/* ******************************* FUNCTIONS ******************************** */
/* MAIN_PARSER */
t_tree	*parser(char *str, int len);
/* SUB_PARSER */

/* TREE */
t_tree	*init_tree_node(int type);
t_tree	*make_parent_tree(t_tree *child, bool direction, int type);

#endif