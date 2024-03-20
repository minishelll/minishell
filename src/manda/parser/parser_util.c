/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/20 19:38:01 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_error.h"

static int	skip_quote(char *str, char quote_type)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote_type)
			return (i);
		i++;
	}
	// if (str[i] == '\0')
		// ft_error(SYNTAX_PAIR, quote);
	return (NOT_FOUND);
}
