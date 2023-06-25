/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:37:43 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/17 09:37:59 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(len + 1, sizeof(char));
	if (s3 != NULL)
	{
		ft_strlcpy(s3, s1, len + 1);
		ft_strlcat(s3, s2, len + 1);
	}
	return (s3);
}
