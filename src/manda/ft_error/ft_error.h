/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:39:03 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/19 18:48:46 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <string.h>
# include <errno.h>
# include <stdio.h>

# define SYSTEMCALL_FAILURE -100

# define OUTPUT_REDIRECTION_ERROR -5
# define INPUT_REDIRECTION_ERROR -4
# define SYNTEX_ERROR -3
# define ACCESS_ERROR -2

# define ERROR -1
# define FAILURE -1
# define SUCCESS 0
# define DO_NOTHING 2

void	ft_error(int error_case, char *target);

#endif