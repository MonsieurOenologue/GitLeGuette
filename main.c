#include "minish.h"

int main(void){
    pthread_t pth;
    int i = 0;

    //Thread creation
    pthread_create(&pth, NULL, threadMain, "chargement du thread");

    //Waits for the thread specified to terminate
    pthread_join(pth, NULL);

    while(i < 10){
        usleep(100);
        printf("main running, c'est super\n");
        i++;
    }

    return 0;
}
