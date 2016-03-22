#include "minish.h"

//printf le résultat d'un ls



//thread bonjour
pthread_t threadId[1];

void * threadMain(void *arg){
    unsigned long i = 0; 
    char *str;

    str=(char*)arg;

    while(i < 10){
        usleep(1);
        printf("threadMain : %s\n", str);
        i++;
    }
    return 0;
}





//Algo
//while not EOF(stdin)
//do
//    read(cmd);
//    fork();
//    child: exec(cmd);
//    parent : wait (child)
