/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:43:42 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/16 22:03:01 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "libft.h"
# include <stdbool.h>
# define PIPE 0
# define AND 1
# define OR 2

typedef struct s_tree	t_tree;
typedef struct s_pipe	t_pipe;
typedef struct s_redi	t_redi;

typedef struct s_tree
{
	int		type;
	t_tree	*left;
	t_tree	*right;
	t_pipe	*pipe;
}			t_tree;

typedef struct s_pipe
{
	char	**cmds;
	t_redi	*in;
	t_redi	*out;
	t_pipe	*next;
}			t_pipe;

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

void	tree_init(t_tree *tree);
t_tree	*tree_new_node(void);
t_tree	*tree_make_child(t_tree *parent, t_pipe *content, bool direction);	

#endif