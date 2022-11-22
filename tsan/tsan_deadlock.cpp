#include <thread>
#include <mutex>
#include <stdio.h>
#include <string>
#include <map>

std::mutex resourceA;

std::mutex resourceB;

void threadFuncA() {
    resourceA.lock();

    resourceB.lock();
}

void threadFuncB() {
    resourceB.lock();

    resourceA.lock();
}

int main() {
  pthread_t t;
  std::thread threadA(threadFuncA);
  std::thread threadB(threadFuncB);

  threadA.join();
  threadB.join();

}