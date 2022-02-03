#include <Windows.h>
#include <iostream>
#include <sys/stat.h>
#include <strsafe.h>
#include <string>
#include <list>
#include <fstream>

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

const char* ws2cc(wstring s) {
    const wchar_t *input = s.c_str();

    size_t size = (wcslen(input) + 1) * sizeof(wchar_t);
    char *buffer = new char[size];

    wcstombs(buffer, input, size);

    return buffer;
}

int main(int argc,char *argv[]) {

    if (system("net session 2> Nul 1> Nul")!=0) {
        system(ws2s(L"start /b cmd.exe /r \"ping 0.0.0.0 -n 1 -w 100 > Nul & powershell start -verb runas '"+s2ws(argv[0])+L"' > Nul\""));
        _exit(0);
    }

    list<string> const files = {"devcon.exe","mouselock.ahk","keyboardlock.ahk","taskmanagerassasin.exe","nircmd.exe"};
    struct stat buffer;
    for (list<string>::const_iterator i = files.begin(); i != files.end(); ++i) {
        if (!(stat (i->c_str(), &buffer) == 0)) {
            system(ws2s(L"curl -l \"https://raw.githubusercontent.com/reedthorngag/device-lock/main/" + s2ws(i->c_str()) + L"\" --output " + s2ws(i->c_str())));
        }
    }

    ifstream in("password.txt");
    string contents((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    

    system("start AutoHotkey keyboardlock.ahk > Nul");
    system("start AutoHotkey mouselock.ahk > Nul");
    system("start /b taskmanagerassasin.exe > Nul");
    system("devcon disable \"HID\\VID_04F3&UP:000D_U:0005\" > Nul");
    system("nircmd win hide class Shell_TrayWnd");

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
    system("devcon enable \"HID\\VID_04F3&UP:000D_U:0005\" > Nul");
    system("nircmd win show class Shell_TrayWnd");

}