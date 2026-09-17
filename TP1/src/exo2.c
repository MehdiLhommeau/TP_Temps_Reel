/*
 * Exercice 2 -- Dix processus fils
 *
 * Squelette a completer.
 * But : creer 10 processus fils ; chaque fils affiche 10 fois son
 * numero d'ordre (0 a 9), soit 100 caracteres affiches au total.
 *
 * Question 2 (enrichie) : une fois la boucle de creation ecrite,
 * observez les zombies (sleep + ps) AVANT d'ecrire la boucle de
 * waitpid(), puis ajoutez cette boucle pour les faire disparaitre.
 *
 * Compilation : gcc exo2.c -o exo2
 * Execution   : ./exo2
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NB_FILS 10
#define NB_AFFICHAGES 10

int main(void) {
    pid_t pids[NB_FILS];

    for (int i = 0; i < NB_FILS; i++) {

        /* TODO (question 1) : creez le processus fils numero i avec
         * fork(). Stockez son PID dans pids[i] cote pere.
         */
        pid_t pid = -1; /* <-- remplacez par l'appel a fork() */

        if (pid < 0) {
            /* ne devrait plus arriver une fois fork() appele */
            fprintf(stderr, "TODO : completer le fork() ci-dessus\n");
            exit(1);
        } else if (pid == 0) {
            /* TODO (question 1) : dans le fils, affichez NB_AFFICHAGES
             * fois le chiffre i (par exemple avec printf("%d", i)),
             * puis terminez le fils avec exit(i) (utile pour la
             * question 2 : le code de retour permettra de verifier
             * que chaque fils est bien identifie par le pere).
             */

            exit(i);
        }

        pids[i] = pid;
    }

    printf("\n");

    /* TODO (question 2, premiere manipulation) :
     * - ajoutez temporairement un sleep(5) au debut du code du fils,
     *   ci-dessus, avant son premier affichage ;
     * - commentez la boucle waitpid() ci-dessous ;
     * - relancez le programme et, dans un autre terminal, executez
     *   `ps aux | grep exo2` pendant les 5 secondes puis juste apres :
     *   observez la colonne STAT (code Z = zombie) pour les fils
     *   deja termines mais pas encore attendus par le pere.
     */

    /* TODO (question 2, suite) : decommentez et completez cette boucle
     * pour attendre chaque fils avec waitpid(), et affichez son code
     * de retour recupere via WIFEXITED / WEXITSTATUS.
     */
    /*
    for (int i = 0; i < NB_FILS; i++) {
        int status;
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status)) {
            printf("Fils %d (PID %d) termine avec le code %d\n",
                   i, pids[i], WEXITSTATUS(status));
        }
    }
    */

    return 0;
}
