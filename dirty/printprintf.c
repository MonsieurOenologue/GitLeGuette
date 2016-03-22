#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>


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
  printf("%d\n", execvp(parsed[0], parsed));
  //printf("%d\n", execlp(parsed_list, parsed_list, 0));

  return 1;
}
// int exec(char *prompt) {
//   //char *arguments[] = argv;
//   //char *supertoast = "ls";
//   printf("%s", prompt);
//   //char data[] = "ls -la";
//   char *command = (char*) strtok(prompt, " ");
//   while(command != NULL) {
//     printf("%s\n", command);
//     command = strtok(command, " ");
//   }
  //execlp(command, command, 0);
  //printf("%s", command);
//  return 1;
//}
/*int exec(char *command) {
  char *arguments[] = {command, NULL};
  return execvp(arguments[0], arguments);
}*/
