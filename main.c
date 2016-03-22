#include "minish.h"

#define MAX_LENGTH 1024

int main(int argc, char **args){
    pid_t pid;
    struct timeval start, stop;

    /*Check parameter*/

    char *name[MAX_LENGTH];
    printf("Hello to minish, the barely usable shell. \nWhat's your name ?\nName : ");
    scanf("%s", &name);
    switch(pid = fork()){
        case -1 : perror("fork failed");
            exit(2);
        case 0 :
            /* child process*/
            //execvp(args[1], args+1);
            //char data[] = "ls -la /home/uj";
            //char data[] = "ls -la ";
            test_exec("ls -la");
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
        printf("%s\>$ ", name);
        if(!fgets(line, MAX_LENGTH, stdin)){
            break;
        }
        system(line);
    }
    /*Fin du copie collage*/

    return 0;
}
