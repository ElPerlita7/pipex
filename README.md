# pipex

🧩 Pipex – 42 Project

📖 Descripción

Pipex es un proyecto del plan de estudios de 42 que replica el comportamiento de las pipes (|) en la shell de Unix.
El objetivo es comprender cómo funcionan las redirecciones, la comunicación entre procesos y el uso de fork(), pipe(), dup2() y execve().

El programa debe ejecutar un comando que toma un archivo como entrada y pasa su salida como entrada a otro comando, para finalmente guardar el resultado en un archivo de salida, emulando:

< infile cmd1 | cmd2 > outfile

⚙️ Uso

Compilación

make

Esto genera el ejecutable pipex.

./pipex infile "cmd1" "cmd2" outfile

Ejemplo

./pipex input.txt "grep hello" "wc -l" output.txt


Equivale a ejecutar en shell:

< input.txt grep hello | wc -l > output.txt

🧠 Conceptos Aprendidos

Manejo de procesos (fork, waitpid)
Comunicación entre procesos (pipe)
Redirección de descriptores (dup2)
Ejecución de comandos (execve)
Rutas del sistema (PATH)
Gestión de errores y permisos

🧩 Archivos Principales

Archivo	Descripción
pipex.c	Función principal, control del flujo y errores
pipex.h	Prototipos y estructuras
utils.c	Funciones auxiliares (split, free, path, etc.)
Makefile	Compilación automatizada
libft/	Biblioteca auxiliar (si se usa)

🧪 Testeo

Comparación con Shell

Para verificar el funcionamiento comparando la salida con la de la shell:

./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l > outfile2
diff outfile outfile2


Si no hay salida en diff, el programa funciona correctamente.

👨‍💻 Autor

ElPerlita
Joseador de Código
📍 42 Madrid
💬 GitHub
