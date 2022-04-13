// int	recording_map(char **split_file, char ***map)
// {
// 	int		i;
// 	int		j;
// 	char	*map_tmp;
// 	char	*tmp;

// 	i = 0;
// 	tmp = ft_strdup("");
// 	while (split_file[i])
// 	{
// 		j = 0;
// 		while (split_file[i][j])
// 		{
// 			if (split_file[i][j] == ' ' || split_file[i][j] == '1' || split_file[i][j] == '0' || split_file[i][j] == 'N' || split_file[i][j] == 'S' || split_file[i][j] == 'W' || split_file[i][j] == 'E')
// 			{
// 				j++;
// 			}
// 			else
// 			{
// 				perror("split_file[i][j] != ' ' ");
// 				return (1);
// 			}
// 		}
// 		i++;
// 	}
// 	*map = split_file;
// 	return (0);
// }