#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
int  PID;
if ((PID= fork()) == 0 )
    {   /* processus fils */
        printf("Le fils : mon PID est %d, le PID de mon pere est %d \n", getpid(), getppid());
        printf("\t\t for a retourne au fils la valeur %d\n",PID);
	}
    else if (PID > 0)
	{
        sleep(2);
        printf("Le pere : mon PID est %d, le PID de mon pere est %d \n", getpid(),getppid() );
        printf("\t\t for a retourne au pere la valeur %d\n",PID);
	}
    else perror("Erreur dans fork !!!");
return 0;
}
