/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:47:24 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/06/25 16:31:24 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list get_correct_file(t_list **file, int fd)
{
	t_list temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew('\0', fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	t_list *curr;
	static t_list *file;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	curr = get_correct_file(&file, fd);

}
