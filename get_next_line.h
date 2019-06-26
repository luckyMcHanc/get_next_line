/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:40:04 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/06/26 15:20:58 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft.h>

# define BUFF_SIZE 100

# define MALLCHECK(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);

#endif
