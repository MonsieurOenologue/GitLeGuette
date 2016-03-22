#include "minish.h"

#define MAX_LENGTH 1024

int main(int argc, char **args){
    //pthread_t pth; //Au revoir les threads
    int i = 0;
    pid_t pid;
    struct timeval start, stop;

    switch(pid = fork()){
        case -1 : perror("fork failed");
            exit(2);
        case 0 :
            /* child process*/
            execvp(args[1], args+1);
            exit(0);
        default:

        //Change this part (extract from myTime.c, TD1 exo4)
        /*parent process waits for child to complete*/
        waitpid(pid, 0, 0);

        /*stop chrono*/
        gettimeofday(&stop, 0);

        printf("time: %f ms\n", (stop.tv_usec - start.tv_usec + 1000000.0 * (stop.tv_usec - start.tv_usec)) / 1000);

    }

    //A supprimer
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




    //@deprecated Au revoir les threads
    /*
    //Thread creation
    pthread_create(&pth, NULL, threadMain, "chargement du thread");

    //Waits for the thread specified to terminate
    pthread_join(pth, NULL);

    while(i < 10){
        usleep(100);
        printf("main running, c'est super\n");
        i++;
    }

    pthread_exit(pth);
    */
    return 0;
}
