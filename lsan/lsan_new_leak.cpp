#include <stdlib.h>

void *p;

int main() {
  p = new char[10];
  p = 0; // The memory is leaked here.
  return 0;
}