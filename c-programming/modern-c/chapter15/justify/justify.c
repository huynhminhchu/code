#include <string.h>
#include "line.h"
#include "word.h"

#include <stdio.h>
#define MAX_WORD_LEN 20

int main(void)
{
  char word[MAX_WORD_LEN+2];
  int word_len;

  clear_line();
  for (;;) {
    word_len = read_word(word, MAX_WORD_LEN+1);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
    
  }
}

//    C      is quirky,     flawed,        and   an 
// enormous   success.          Although  accidents of     history
//  surely  helped,      it  evidently     satisfied   a     need
 
//      for   a    system   implementation        language     efficient
//    enough    to    displace            assembly      language,
//       yet sufficiently       abstract     and  fluent        to describe 
//      algorithms    and      interactions     in a    wide       variety
//   of environments.
