/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:25:29 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/08 20:24:21 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const size_t	findlen = ft_strlen(to_find);
	size_t			i;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0] && len - i > findlen)
			if (ft_strcmp(&str[i], to_find) == 0)
				return ((char *)(str + i));
		i++;
	}
	return (0);
}
