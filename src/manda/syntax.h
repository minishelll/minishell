/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:39:44 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/16 22:00:50 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include <stdbool.h>

typedef struct s_redi	t_redi;

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

#endif