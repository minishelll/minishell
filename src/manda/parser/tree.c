/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:57:44 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/17 23:23:08 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

/*malloc new t_tree node*/
t_tree	*init_tree_node(void)
{
	t_tree	*new;

	new = ft_malloc(sizeof(t_tree));
	new->type = INIT;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/*append existing tree under a new node*/
t_tree	*make_parent_tree(t_tree *child, bool direction, int type)
{
	t_tree	*parent;

	parent = init_tree_node();
	parent->type = type;
	if (direction == LEFT)
		parent->left = child;
	else
		parent->right = child;
	return (parent);
}
