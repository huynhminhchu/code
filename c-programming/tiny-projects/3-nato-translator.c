#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Input: Howdy */
/* Output: Hotel Oscar Whiskey Delta Yankee */

/* Input 2: Hello, World! */
/* Output 2: Hotel Echo Lima Lima Oscar Whiskey Osca Romeo Lima Delta */

#define BUFSIZE 256

int char_to_ascii(char c) {
  if (isalpha(c)) {
    return toupper((int)c) - 65;
  }
  return -1;
  // a -> return "Alfa";
}

int main(int argc, char *argv[]) {
  char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  char buf[BUFSIZE];
  int length = sizeof(nato) / sizeof(char *);

  while (true) {
    printf("Input: ");
    fgets(buf, BUFSIZE, stdin);
    // fgets will read a newline-terminated string
    printf("You entered: %s", buf);
    for (int i = 0; i < strlen(buf); i++) {
      int index = char_to_ascii(buf[i]);
      if (index != -1) {
        printf("%s ", nato[index]);
      }
    }
    printf("\n");
  }
  return 0;
}
