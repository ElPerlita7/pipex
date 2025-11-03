/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:34:17 by abferrer          #+#    #+#             */
/*   Updated: 2025/11/03 16:44:40 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "./libft/libft.h"

void	ft_error(char *msg);
char	*get_path(char *cmd, char **envp);
void	free_tab(char **matrix);
void	execute(char *cmd, char **envp);

#endif
