/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:34:02 by abferrer          #+#    #+#             */
/*   Updated: 2025/11/11 20:44:31 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free (temp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_tab(paths), full_path);
		free(full_path);
	}
	return (free_tab(paths), NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	if (!cmds || !cmds[0])
	{
		free_tab(cmds);
		(ft_error("Commands not found"), exit(127));
	}
	if (ft_strchr(cmds[0], '/'))
		path = ft_strdup(cmds[0]);
	else
		path = get_path(cmds[0], envp);
	if (!path || access(path, X_OK))
	{
		free_tab(cmds);
		free(path);
		ft_putstr_fd("Command not found", 2);
		exit(127);
	}
	execve(path, cmds, envp);
	free(path);
	free_tab(cmds);
	perror("Execve failed\n");
	exit(127);
}

void	free_tab(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
