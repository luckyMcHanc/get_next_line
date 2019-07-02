/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:47:24 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/02 16:01:56 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*get_file(t_list **file, int fd)
{
	t_list *temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_list			*corret;
	int				ret;
	static t_list	*file;
	int				i;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	corret = get_file(&file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((corret->content = ft_strjoin(corret->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(corret->content))
		return (0);
	i = ft_copyuntil(line, corret->content, '\n');
	(i < (int)ft_strlen(corret->content))
		? corret->content += (i + 1)
		: ft_strclr(corret->content);
	return (1);
}
