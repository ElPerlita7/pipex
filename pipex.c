/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:36:48 by abferrer          #+#    #+#             */
/*   Updated: 2025/09/12 12:38:31 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void hijo(char **argv, char **envp, int *fd) {
    int input_file;
    // argv[1] es el fichero o directorio de entrada
    input_file = open(argv[1], O_RDONLY, 0777);
    if (input_file == -1) {
        ft_error("Error reading input file...");
    }

    dup2(fd[1], STDOUT_FILENO);
    dup2(input_file, STDIN_FILENO);
    close(fd[0]);
    close(input_file);
    
    ejecutar(argv[2], envp);
}

void padre(char **argv, char **envp, int *fd) {
    int output_file;
    // argv[4] es el fichero o directorio de salida
    output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (output_file == -1) {
        ft_error("Error writing output file...");
    }

    dup2(fd[0], STDIN_FILENO);
    dup2(output_file, STDOUT_FILENO);
    close(fd[1]);
    close(output_file);

    ejecutar(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{

    int pipe_fd[2];
    pid_t pid1;

    if (argc != 5)
        ft_error("Invalid arguments number");

    if (pipe(pipe_fd) == -1)
        ft_error("Error getting pipe");

    pid1 = fork();
    // -1 no se ha creado
    if (pid1 == -1) {
        ft_error("Error creating pid...");
    }

    // 0 se ha creado el proceso hijo correctamente
    if (pid1 == 0) {
        // lanza las cosas del hijo
        hijo(argv, envp, pipe_fd);
    }

    // esperar al pid del hijo
    waitpid(pid1, NULL, 0);

    // ejecutar el padre
    padre(argv, envp, pipe_fd);
    
    return 0;
}