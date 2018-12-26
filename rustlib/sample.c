// Build this by
// $ gcc -o sample sample.c libdemo.a or
// $ gcc -o sample sample.c -L. -ldemo
#include <stdint.h> // uint32_t
#include <stdio.h>  // printf

extern uint32_t cubic(uint32_t x);

int main() {
  uint32_t x = 10;
  printf("cubic of %d is %d\n", x, cubic(x));
  return 0;
}