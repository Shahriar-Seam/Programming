#include "stdio.h"
#include <ctype.h>
#include <string.h>
//codeforces 443A
int main() {
  char input[2000];
  int storage[2000],ascii=0, i, l = 0, count = 0;
  scanf("%s", &input);
  l = strlen(input);

  /*
    for (i = 0; i < 128; i++) {
    storage[i] = 0; // make everything zero in storge[]
    // printf("%d ",storage[i]); // init with garbage value
  }
  for (i = 0; i < 128; i++) {
    if ((input[i] >= 65 && input[i] <= 90)) {
      storage[i]++;
      printf("%d ",storage[i]);
    }
  }
*/
  for (i = 0; i < 128; i++) {
    ascii = toascii(input[i]);
    if (ascii >= 65 && ascii <= 90) {
        storage[ascii] = 1;
    }
    else {
    storage[ascii] = 0;
    }
  }
  for (i = 0; i < 128; i++) {
    if (storage[i] == 1) {
      count++;
    }
  }
  printf("%d", count);

  return 0;
}