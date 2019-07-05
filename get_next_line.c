/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:00:45 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/05 13:02:34 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				read_file(int fd, char **cont)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *cont;
		if (!(*cont = ft_strjoin(*cont, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				read_line(char **line, char *cont, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (cont[i] && cont[i] != c)
		i++;
	if (!(*line = ft_strndup(cont, i)))
		return (0);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	t_list			*list;
	static t_list	*file;

	if (fd < 0 || line == NULL || (read(fd, buf, 0) < 0))
		return (-1);
	list = get_file(&file, fd);
	tmp = list->content;
	ret = read_file(fd, &tmp);
	list->content = tmp;
	if (!ret && !*tmp)
		return (0);
	ret = read_line(line, list->content, '\n');
	tmp = list->content;
	if (tmp[ret] != '\0')
	{
		list->content = ft_strdup(&((list->content)[ret + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
