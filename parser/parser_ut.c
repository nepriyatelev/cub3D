
void	reading_a_file(char ***split_file, int fd)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(2 * sizeof(char));
	if (buf == NULL)
	{
		perror("buf == NULL ");
		exit(EXIT_FAILURE);
	}
	tmp = ft_strdup("");
	if (tmp == NULL)
	{
		perror("tmp == NULL ");
		free(buf);
		exit(EXIT_FAILURE);
	}
	buf[1] = '\0';
	while ((read(fd, &buf[0], 1)) > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
		{
			perror("buf == NULL ");
			free(buf);
			free(tmp);
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	*split_file = ft_split(tmp, '\n');
	free(tmp);
}

int	recording_textures(char *line, char **nswe)
{
	int	fd;
	int	i;
	int	j;

	fd = 0;
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (line[j] && line[j] != '\n' && !(ft_isspace(line[j])))
		j++;
	*nswe = ft_substr(line, i, j - i);
	if (*nswe == NULL)
	{
		perror("*nswe == NULL ");
		return (1);
	}
	fd = open(*nswe, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		free(*nswe);
		return (1);
	}
	if (fd > -1)
		close(fd);
	return (0);
}

int	checking_nswe(char **split_file, char *nswe)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (split_file[i])
	{
		if (!(ft_strncmp(split_file[i], nswe, 2)))
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	checking_color(char **split_file, char *color)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (split_file[i])
	{
		if (!(ft_strncmp(split_file[i], color, 1)))
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	recording_color(char *line, int	**color)
{
	int		i;
	int		j;
	int		tmp_d;

	char **tmp;
	i = 1;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (line[j] && line[j] != '\n' && !ft_isspace(line[j]))
	{
		if (ft_isdigit(line[j]) || line[j] == ',')
			j++;
		else
		{
			perror("not digit or , ");
			return (1);
		}
	}
	*color = (int *)malloc(sizeof(int) * 3);
	if (*color == NULL)
		return (1);
	tmp = ft_split(ft_substr(line, i, j - i), ',');
	if ((ft_strlen(*tmp)) != 3)
	{
		perror("if (ft_strlen(tmp[i] != 3)) ");
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		tmp_d = ft_atoi(tmp[i]);
		if (tmp_d <= 255 && tmp_d >= 0)
		{
			(*color)[i] = tmp_d;
			i++;
		}
		else
		{
			perror("(tmp_d <= 255 && tmp_d >= 0) ");
			return (1);
		}
	}
	return (0);
}

int	checking_the_file(char **split_file, t_data *data)
{
	int	i;

	i = 0;
	while (split_file[i])
	{
		if (!(ft_strncmp(split_file[i], "NO", 2)))
		{	if (recording_textures(split_file[i], &data->texture.north))
				return (1);}
		else if (!(ft_strncmp(split_file[i], "SO", 2)))
		{	if (recording_textures(split_file[i], &data->texture.south))
				return (1);}
		else if (!(ft_strncmp(split_file[i], "WE", 2)))
		{	if (recording_textures(split_file[i], &data->texture.west))
				return (1);}
		else if (!(ft_strncmp(split_file[i], "EA", 2)))
		{	if (recording_textures(split_file[i], &data->texture.east))
				return (1);}
		else if (!(ft_strncmp(split_file[i], "F", 1)))
		{	if (recording_color(split_file[i], &data->texture.color_floor))
				return (1);}
		else if (!(ft_strncmp(split_file[i], "C", 1)))
		{	if (recording_color(split_file[i], &data->texture.color_ceiling))
				return (1);}
		i++;
	}
	return (0);
}

int	recording_map(char **split_file, char ***map)
{
	int		i;
	int		j;
	char	*map_tmp;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	while (split_file[i])
	{
		j = 0;
		while (split_file[i][j])
		{
			if (split_file[i][j] == ' ' || split_file[i][j] == '1' || split_file[i][j] == '0' || split_file[i][j] == 'N' || split_file[i][j] == 'S' || split_file[i][j] == 'W' || split_file[i][j] == 'E')
			{
				j++;
			}
			else
			{
				perror("split_file[i][j] != ' ' ");
				return (1);
			}
		}
		i++;
	}
	*map = split_file;
	return (0);
}