#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <chrono>
#include <ctime>

using namespace std;

int procedure() {
    return 0;
}

int main() {
    int iterations = 10000000;

    auto startSysCall = std::chrono::system_clock::now();
    for (int i = 0; i < iterations; i++) {
        chmod("file.txt", S_IWUSR);
    }
    auto endSysCall = std::chrono::system_clock::now();

    std::chrono::duration<double> timeSysCall = endSysCall - startSysCall;

    auto startProcCall = std::chrono::system_clock::now();
    for (int i = 0; i < iterations; i++) {
        procedure();
    }
    auto endProcCall = std::chrono::system_clock::now();

    std::chrono::duration<double> timeProcCall = endProcCall - startProcCall;

    cout << timeSysCall.count() << " " << timeProcCall.count() << endl;
}