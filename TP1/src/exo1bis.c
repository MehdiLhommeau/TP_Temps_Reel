/*
 * Exercice 1bis -- Predire avant d'executer, et copie memoire
 *
 * Programme fourni complet : rien a completer. Predisez sur votre
 * feuille la valeur de x affichee par le fils puis par le pere
 * AVANT de compiler et d'executer.
 *
 * Compilation : gcc exo1bis.c -o exo1bis
 * Execution   : ./exo1bis
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {
    int x = 10;
    pid_t pid = fork();

    if (pid == 0) {
        x = x + 5;
        printf("[FILS]  x = %d (PID %d)\n", x, getpid());
    } else {
        sleep(1); /* laisse le fils s'executer et afficher en premier */
        printf("[PERE]  x = %d (PID %d)\n", x, getpid());
    }
    return 0;
}
