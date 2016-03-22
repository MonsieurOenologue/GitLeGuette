#include "minish.h"

#define MAX_LENGTH 1024

int main(int argc, char **args){
    pid_t pid;

    /*Check parameter*/


    /* start chrono */
    char line[MAX_LENGTH];

    switch(pid = fork()){
        case -1 : perror("fork failed");
            exit(2);
        case 0 :
            /* child process*/
            //execvp(args[1], args+1);
            //char data[] = "ls -la /home/uj";
            //char data[] = "ls -la ";
            scanf("%s", &line);
            test_exec(line);
            exit(0);

        default:

        //Change this part (extract from myTime.c, TD1 exo4)
        /*parent process waits for child to complete*/
        waitpid(pid, 0, 0);





    }

    //A supprimer
    /*Copie collage nul*
    //
    // while(1){
    //     printf("$ ");
    //     /*if(!fgets(line, MAX_LENGTH, stdin)){
    //         break;
    //     }*/
    //     scanf("%s", &line);
    //     test_exec(line);
    // }

    return 0;
}
