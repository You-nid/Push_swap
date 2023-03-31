/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:55:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 20:46:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static size_t	ft_find_len(const char *s, size_t *new_l)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		++len;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			*new_l = i + 1;
			break ;
		}
		++i;
	}
	return (len);
}

static char	*ft_read(char *str, int fd)
{
	char	*buff;
	size_t	len;

	len = 1;
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (len > 0 && !ft_strchr(buff, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		str = ft_strjoin_get(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat;
	size_t		len;
	size_t		new_l;

	len = 0;
	new_l = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stat)
		stat = ft_calloc(1, 1);
	stat = ft_read(stat, fd);
	if (!stat)
		return (NULL);
	len = ft_find_len(stat, &new_l);
	if (new_l == 0)
		new_l = len;
	line = ft_get_line(&stat, new_l);
	stat = ft_get_next(stat, new_l, len);
	return (line);
}
