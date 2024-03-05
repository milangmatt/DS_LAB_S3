#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    pid_t pid;
    int status;

    // Forking a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process

        // Example of exec() usage
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl() returns, an error occurred
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Example of getpid() usage
        printf("Parent PID: %d\n", getpid());

        // Example of wait() usage
        wait(&status);
        printf("Child process exited with status: %d\n", status);

        // Example of opendir() and readdir() usage
        DIR *dir;
        struct dirent *entry;
        dir = opendir(".");
        if (dir == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }
        printf("Contents of current directory:\n");
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    }

    // Example of exit() usage
    exit(EXIT_SUCCESS);
}