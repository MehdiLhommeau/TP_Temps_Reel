/*
 * Exercice 1ter -- Arbre de forks multiples
 *
 * Programme fourni complet : rien a completer. Avant d'executer,
 * dessinez sur papier l'arbre des processus crees et comptez
 * combien de fois "Bonjour" sera affiche.
 *
 * Compilation : gcc exo1ter.c -o exo1ter
 * Execution   : ./exo1ter
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {
    fork();
    fork();
    printf("Bonjour (PID %d, PPID %d)\n", getpid(), getppid());
    return 0;
}
