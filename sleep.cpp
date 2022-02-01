#include <windows.h>
#include <iostream>
#include <sys/stat.h>
#include <string>
#include <sstream>
#include <list>

using namespace std;

wstring s2ws(string str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

const char* ws2s(wstring s) {
    const wchar_t *input = s.c_str();

    size_t size = (wcslen(input) + 1) * sizeof(wchar_t);
    char *buffer = new char[size];

    wcstombs(buffer, input, size);

    return buffer;
}

int main() {
    list<string> const files = {"devcon.exe","mouselock.ahk","keyboardlock.ahk","taskmanagerassasin.exe"};
    struct stat buffer;
    for (list<string>::const_iterator i = files.begin(); i != files.end(); ++i) {
        cout << "thig: " << i->c_str() << endl;
        if (!(stat (i->c_str(), &buffer) == 0)) {
            system(ws2s(L"curl -l \"https://raw.githubusercontent.com/reedthorngag/computer-lock/main/" + s2ws(i->c_str()) + L"\" --output " + s2ws(i->c_str())));
        }
    }
    system("start AutoHotkey keyboardlock.ahk");
    system("start AutoHotkey mouselock.ahk");
    system("start taskmanagerassasin.exe");
    system("devcon.exe disable \"HID\\VID_04F3&UP:000D_U:0005\"");

    system("cls");
    string password_input;
    cout << "enter password: " << flush;
    cin >> password_input;
    while (password_input!="hello") {
        system("cls");
        cout << "wrong password!" << endl;
        Sleep(3000);
        system("cls");
        cout << "enter password: " << flush;
        cin >> password_input;
    }

    system("taskkill /F /IM AutoHotkey.exe /T > Nul");
    system("taskkill /F /IM taskmanagerassasin.exe /T > Nul");
    system("devcon.exe enable \"HID\\VID_04F3&UP:000D_U:0005\"");
}