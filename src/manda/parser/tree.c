/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:57:44 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/17 04:22:29 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*initailize t_tree node*/
void	tree_init(t_tree *tree)
{
	tree->left = NULL;
	tree->right = NULL;
	tree->pipe = NULL;
	tree->type = 0;
	return ;
}

/*malloc new t_tree node*/
t_tree	*tree_new_node(void)
{
	t_tree	*new_node;

	new_node = ft_malloc(sizeof(t_tree));
	tree_init(new_node);
	return (new_node);
}

/*make and append new child node to parent node*/
t_tree	*tree_make_child(t_tree *parent, t_pipe *content, bool direction)
{
	t_tree	*child;

	child = tree_new_node();
	if (direction == 0)
		child->left->pipe = content;
	else
		child->right->pipe = content;
	return (child);
}

t_tree	*tree_make_parent(t_tree *child, int type)
{
	t_tree	*parent;

	parent = tree_new_node();
	parent->left = child;
	parent->type = type;
	return (parent);
}
