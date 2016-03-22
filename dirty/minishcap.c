#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 256
int main(int argc, char const *argv[]) {
  char *name[MAX_LEN];
  printf("Hello to minish, the barely usable shell. \nWhat's your name ?\nName : ");
  scanf("%s", &name);
  while(1) {
  char prompt[MAX_LEN];
    printf("%s $ ", name);
    scanf("%s", &prompt);
  }
  return 0;
}
