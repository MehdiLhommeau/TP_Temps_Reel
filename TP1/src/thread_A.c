/*
 * Serie progressive threads -- Etape A : un seul thread
 *
 * But : creer un thread qui affiche un message, puis attendre sa fin
 * avec pthread_join avant que le programme principal n'affiche le sien.
 *
 * Compilation : gcc thread_A.c -o thread_A -pthread
 * Execution   : ./thread_A
 */

#include <stdio.h>
#include <pthread.h>

void *ma_fonction(void *arg) {
    (void)arg;

    /* TODO : affichez "Je suis le thread numero 1" (ou tout numero
     * fixe en dur pour cette premiere version).
     */

    return NULL;
}

int main(void) {
    pthread_t tid;

    /* TODO : creez le thread avec pthread_create(), en lui passant
     * ma_fonction comme fonction a executer.
     */

    /* TODO : attendez la fin du thread avec pthread_join() avant
     * d'afficher le message ci-dessous.
     */

    printf("[MAIN] le thread est termine, fin du programme.\n");
    return 0;
}
