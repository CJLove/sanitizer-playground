#include <thread>
#include <stdio.h>
#include <string>
#include <map>

typedef std::map<std::string, std::string> map_t;


void threadfunc(void *p) {
    map_t &m = *(map_t*)p;
    m["foo"] = "bar";
    return;
}

int main() {
    map_t m;
    std::thread threadA(threadfunc,&m);
    printf("foo=%s\n", m["foo"].c_str());
    threadA.join();
}
