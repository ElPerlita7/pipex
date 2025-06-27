/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:36:48 by abferrer          #+#    #+#             */
/*   Updated: 2025/06/26 20:38:22 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{

    int pipe_fd[2];

    if (argc != 5)
        ft_error("Invalid arguments number");

    if (pipe(pipe_fd) == -1)
        ft_error("Error getting pipe");
    
    return 0;
}