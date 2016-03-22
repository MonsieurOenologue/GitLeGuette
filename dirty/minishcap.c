#include <stdio.h>
#include <stdlib.h>
#include "printprintf.h"
#define MAX_LEN 256
int main(int argc, char const *argv[]) {
  char *name[MAX_LEN];
  printf("Hello to minish, the barely usable shell. \nWhat's your name ?\nName : ");
  scanf("%s", &name);
  char prompt[MAX_LEN];
  while(1) {
    printf("%s $ ", name);
    scanf("%s", &prompt);
    test_exec(prompt);
  }
  return 0;
}
