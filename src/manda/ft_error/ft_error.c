/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:16:58 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/13 17:34:33 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_error.h"
#include "libft.h"

static void	print_msg(int error_case, char *target)
{
	char	*message;

	if (error_case == INPUT_REDIRECTION_ERROR \
	|| error_case == OUTPUT_REDIRECTION_ERROR)
		message = strerror(errno);
	if (error_case == ACCESS_ERROR)
		message = "command not found";
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(target, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error(int error_case, char *target)
{
	if (error_case == SYSTEMCALL_FAILURE)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	print_msg(error_case, target);
	if (error_case == INPUT_REDIRECTION_ERROR)
		return ;
	if (error_case == OUTPUT_REDIRECTION_ERROR)
		exit(EXIT_FAILURE);
	if (error_case == ACCESS_ERROR)
		exit(127);
}
