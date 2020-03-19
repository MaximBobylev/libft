/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:28:33 by hbits             #+#    #+#             */
/*   Updated: 2020/02/07 12:35:21 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static void	st_strext(char **s1, char *s2, size_t s1_len, size_t s2_len)
{
	size_t		i;
	char		*tmp;

	while ((*s1)[s1_len] && !(i = 0))
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	if (!(tmp = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return ;
	while (s1[0][i])
		*tmp++ = s1[0][i++];
	i = 0;
	tmp -= s1_len;
	free(s1[0]);
	if (!(s1[0] = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
	{
		free(tmp);
		return ;
	}
	while (i <= s1_len + s2_len)
		if (i < s1_len)
			s1[0][i++] = *tmp++;
		else
			s1[0][i++] = *s2++;
	free(tmp - s1_len);
}

static char	*st_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	char	*p_copy;

	if (!s || !(*s))
	{
		p = (char *)malloc(1);
		*p = '\0';
		return (p);
	}
	if (len == 0)
		while (s[len])
			len++;
	i = start;
	if (!s)
		return ((char *)NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return ((char *)NULL);
	p_copy = p;
	len += start;
	while (i < len && s[i])
		*p++ = s[i++];
	*p = '\0';
	return (p_copy);
}

static int	gnl_sub(char **tmp, char **p, const int fd, char **line)
{
	if (*tmp)
	{
		(*line) = st_strsub(p[fd], 0, (size_t)((*tmp) - p[fd] + 1));
		(*line)[(*tmp) - p[fd]] = '\0';
		if (**tmp)
		{
			(*tmp) = st_strsub((*tmp) + 1, 0, 0);
			free(p[fd]);
			p[fd] = 0;
			if ((*tmp)[0])
				p[fd] = (*tmp);
			else
				free(*tmp);
		}
		else
		{
			free(p[fd]);
			p[fd] = 0;
		}
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*p[MAX_FD_COUNT];
	int			bytes_read;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	tmp = 0;
	while ((bytes_read = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (p[fd] && buf[0])
			st_strext(&p[fd], buf, 0, 0);
		else if (buf[0])
			p[fd] = st_strsub(buf, 0, bytes_read);
		if ((tmp = ft_strchr(p[fd], '\n')))
			break ;
	}
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0 && (!p[fd] || !p[fd][0]))
		return (0);
	if (!(tmp) && p[fd])
		(tmp) = ft_strchr(p[fd], '\n');
	if (!(tmp) && p[fd])
		(tmp) = ft_strchr(p[fd], '\0');
	return (gnl_sub(&tmp, p, fd, line));
}
