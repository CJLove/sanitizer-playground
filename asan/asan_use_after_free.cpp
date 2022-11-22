#include <cstdlib>
int main() {
  char *x = new char[10];
  delete [] x;
  return x[5];
}