#include <stdio.h>
#include <stdlib.h>

/* Input: Howdy */
/* Output: Hotel Oscar Whiskey Delta Yankee */

/* Input 2: Hello, World! */
/*   Output 2: Hotel Echo Lima Lima Oscar Whiskey Osca Romeo Lima Delta */

int main(int argc, char *argv[]) {
  char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  int length = sizeof(nato) / sizeof(char *);

  printf("Length: %d\n", length);
  for (int i = 0; i < length; i++) {
    printf("Nato code [%d]: %s\n", i + 1, nato[i]);
  }
  return 0;
}
