#include "minish.h"

/*Honnêtement ce fichier ne sert à rien pour le moment*/

//printf le résultat d'un ls
/*
  Exec est une callback
*/
//askip c'est pas nécessaire.


int test_exec(char *data) {
  //char data[] = "ls -larsh /home/uj/dev/";
  //LET'S COUNT PARAMETERS
  int argc = 1;
  char *ptr = data;
  char *tok;
  int i=0;
  while((ptr = strchr(ptr, ' ')) != NULL) {
    argc++;
    ptr++;
  }
  //printf("%d\n", argc);
  char **parsed = malloc((argc+1)*sizeof(char));
  tok = strtok(data, " ");
  while(tok != NULL) {
    //printf("%s\n", tok);
    parsed[i] = strdup(tok);
    tok = strtok(NULL, " ");
    i++;
  }
  parsed[argc] = NULL;
  for(i=0; i<argc; i++) {
    printf("%s\n", parsed[i]);
  }
  //char *parsed[] = {"ls", "-la", "/home/uj", NULL};
  //printf("%d\n", execlp(parsed_list, parsed_list, 0));

  return execvp(parsed[0], parsed);
}


//Algo
//while not EOF(stdin)
//do
//    read(cmd);
//    fork();
//    child: exec(cmd);
//    parent : wait (child)
