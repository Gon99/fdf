/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:48:38 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/15 12:29:05 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static size_t	check_new_line(char *str)
{
	size_t	is_new_line;

	is_new_line = 0;
	if (!str)
		return (is_new_line);
	while (*str != '\0' && is_new_line == 0)
	{	
		if (*str == '\n')
			is_new_line = 1;
		str++;
	}
	return (is_new_line);
}

static char	*get_line(char *str)
{
	size_t	l;
	char	*line;
	int		flag;

	l = 0;
	flag = 0;
	while (str[l++] != '\0' && flag == 0)
	{
		if (str[l] == '\n')
			flag = 1;
	}
	line = malloc(sizeof(char) * (l + 1));
	if (!line)
		return (0);
	l = 0;
	flag = 0;
	while (str[l] != '\0' && flag == 0)
	{
		line[l] = str[l];
		if (str[l] == '\n')
			flag = 1;
		l++;
	}
	line[l] = '\0';
	return (line);
}

static char	*increment_buffer(char *str)
{
	size_t	i;
	int		l;
	char	*new_buff;

	i = 0;
	l = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (i == ft_strlen(str))
	{
		free(str);
		return (0);
	}
	l = ft_strlen(str);
	new_buff = malloc(sizeof(char) * (l + 1));
	if (!new_buff)
		return (0);
	l = 0;
	while (str[i])
		new_buff[l++] = str[i++];
	new_buff[l] = '\0';
	free(str);
	return (new_buff);
}

static int	handle_rs(int rs, char *buff)
{
	int	res;

	res = 0;
	if (rs == -1)
	{
		free(buff);
		return (res);
	}
	res = 1;
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*buff_joined;
	int			rs;

	rs = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (rs > 0 && !check_new_line(buff_joined))
	{
		rs = read(fd, buff, BUFFER_SIZE);
		if (handle_rs(rs, buff) == 0)
			return (0);
		if (rs == 0)
			break ;
		buff[rs] = '\0';
		buff_joined = ft_strjoin(buff_joined, buff);
	}
	free(buff);
	if (!buff_joined || !*buff_joined)
		return (0);
	line = get_line(buff_joined);
	buff_joined = increment_buffer(buff_joined);
	return (line);
}

/*int main()
{
	int	fd;
	int	fd2;
	int fd3;
	char *line;
	char *line2;
	char *line3;

	fd = open("./gnlTester/files/42_no_nl", O_RDONLY);
	fd2 = open("./gnlTester/files/empty", O_RDONLY);
	fd3 = open("./gnlTester/files/nl", O_RDONLY);
	line = get_next_line(fd);
	printf("l1: %s", line);
	line2 = get_next_line(fd2);
	printf("l2: %s", line2);
	line3 = get_next_line(fd3);
	printf("l3: %s", line3);
	while (line != NULL || line2 != NULL || line3 != NULL)
	{
		if (line != NULL)
		{
			printf("l1: %s", line);
			free(line);
			line = get_next_line(fd);
		}
		if (line2 != NULL)
		{
			printf("l2: %s", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
		if (line3 != NULL)
		{
			printf("l3: %s", line3);
			free(line3);
			line3 = get_next_line(fd3);
		}
	}
	//printf("%s", line);
	//free(line);
	close(fd);
	close(fd2);
	close(fd3);
	//system("leaks -q a.out");
	return (0);
}*/
