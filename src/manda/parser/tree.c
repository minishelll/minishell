/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:57:44 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/19 14:11:49 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

/*malloc new t_tree node*/
t_tree	*init_tree_node(int type)
{
	t_tree	*new;

	new = ft_malloc(sizeof(t_tree));
	new->type = type;
	new->child_type[LEFT] = 0;
	new->child_type[RIGHT] = 0;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/*append existing tree under a new node*/
t_tree	*make_parent_tree(t_tree *child, bool direction, int type)
{
	t_tree	*parent;

	parent = init_tree_node(type);
	if (direction == LEFT)
		parent->left = child;
	else
		parent->right = child;
	return (parent);
}
