/*
 * Bilan comparatif -- mesure du cout de creation fork() vs pthread_create()
 *
 * Mesure le temps moyen, sur NB_MESURES repetitions, pour :
 *  (a) creer puis attendre un processus fils qui ne fait rien
 *      (fork + wait) ;
 *  (b) creer puis attendre un thread qui ne fait rien
 *      (pthread_create + pthread_join).
 *
 * Compilation : gcc comparatif_mesure.c -o comparatif_mesure -pthread
 * Execution   : ./comparatif_mesure
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>

#define NB_MESURES 1000

double diff_ms(struct timespec debut, struct timespec fin) {
    return (fin.tv_sec - debut.tv_sec) * 1000.0
         + (fin.tv_nsec - debut.tv_nsec) / 1e6;
}

void *ne_rien_faire(void *arg) {
    (void)arg;
    return NULL;
}

int main(void) {
    struct timespec debut, fin;
    double total_process = 0.0, total_thread = 0.0;

    /* --- (a) mesure fork()/wait() --- */

    /* TODO : dans une boucle de NB_MESURES iterations, mesurez le
     * temps pour faire fork() puis, dans le fils, exit(0)
     * immediatement, et dans le pere wait(NULL). Cumulez le temps
     * ecoule (en ms) dans total_process.
     *
     * Squelette d'une iteration :
     *
     *   clock_gettime(CLOCK_MONOTONIC, &debut);
     *   pid_t pid = fork();
     *   if (pid == 0) {
     *       _exit(0);
     *   }
     *   wait(NULL);
     *   clock_gettime(CLOCK_MONOTONIC, &fin);
     *   total_process += diff_ms(debut, fin);
     */

    /* --- (b) mesure pthread_create()/pthread_join() --- */

    /* TODO : de la meme facon, mesurez NB_MESURES fois le temps pour
     * creer un thread executant ne_rien_faire() puis l'attendre avec
     * pthread_join(). Cumulez dans total_thread.
     *
     * Squelette d'une iteration :
     *
     *   clock_gettime(CLOCK_MONOTONIC, &debut);
     *   pthread_t tid;
     *   pthread_create(&tid, NULL, ne_rien_faire, NULL);
     *   pthread_join(tid, NULL);
     *   clock_gettime(CLOCK_MONOTONIC, &fin);
     *   total_thread += diff_ms(debut, fin);
     */

    printf("Temps moyen fork()+wait()             : %.4f ms\n",
           total_process / NB_MESURES);
    printf("Temps moyen pthread_create()+join()   : %.4f ms\n",
           total_thread / NB_MESURES);

    return 0;
}
