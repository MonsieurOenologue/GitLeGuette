#include "minish.h"

#define MAX_LENGTH 1024

int main(void){
    pthread_t pth;
    int i = 0;

    /*Copie collage nul*/
    char line[MAX_LENGTH];

    while(1){
        printf("$ ");
        if(!fgets(line, MAX_LENGTH, stdin)){
            break;
        }
        system(line);
    }
    /*Fin du copie collage*/

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
