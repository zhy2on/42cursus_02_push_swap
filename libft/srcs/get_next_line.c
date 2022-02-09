/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:43:52 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/01 17:57:27 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	update_line(char **backup, char **line, char *pcut)
{
	char		*tmp;

	*pcut = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(pcut + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	return_case(char **backup, char **line, int rsize)
{
	char		*pcut;

	if (rsize < 0)
		return (-1);
	if (*backup)
	{
		pcut = ft_strchr(*backup, '\n');
		if (pcut)
			return (update_line(backup, line, pcut));
		*line = *backup;
		*backup = NULL;
		return (0);
	}
	*line = ft_strdup("\0");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			rsize;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while ((rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("\0");
		tmp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (return_case(&backup[fd], line, rsize));
}
