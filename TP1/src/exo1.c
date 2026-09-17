/*
 * Exercice 1 -- Creation et identification de processus
 *
 * Ce programme cree un processus fils avec fork() et affiche,
 * dans chaque processus, son PID, le PID de son pere, et la valeur
 * retournee par fork() dans ce processus.
 *
 * Compilation : gcc exo1.c -o exo1
 * Execution   : ./exo1
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;

    printf("Avant le fork() : je suis le processus %d\n", getpid());
    fflush(stdout); /* evite que ce message ne soit affiche deux fois
                        (une fois par le pere, une fois par le fils, qui
                        hérite du tampon de sortie non encore vide) */

    pid = fork();

    if (pid < 0) {
        /* echec du fork() */
        perror("fork");
        return 1;
    } else if (pid == 0) {
        /* on est dans le processus fils */
        printf("[FILS]  fork() a retourne %d | PID=%d | PPID=%d\n",
               pid, getpid(), getppid());
    } else {
        /* on est dans le processus pere, pid = PID du fils */
        printf("[PERE]  fork() a retourne %d | PID=%d | PPID=%d\n",
               pid, getpid(), getppid());
    }

    printf("Processus %d termine.\n", getpid());
    return 0;
}

