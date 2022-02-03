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

int main(int argc,char *argv[]) {

    if (system("net session 2> Nul 1> Nul")!=0) {
        system(ws2s(L"start /b cmd.exe /r \"ping 0.0.0.0 -n 1 -w 100 > Nul & powershell start -verb runas '"+s2ws(argv[0])+L"' > Nul\""));
        _exit(0);
    }

    system("if not exist bin\\ mkdir bin");

    list<string> const files = {"bin\\devcon.exe","bin\\mouselock.ahk","bin\\keyboardlock.ahk","bin\\taskmanagerassasin.exe","bin\\nircmd.exe","bin\\hard-reset.bat"};
    struct stat buffer;
    for (list<string>::const_iterator i = files.begin(); i != files.end(); ++i) {
        if (!(stat (i->c_str(), &buffer) == 0)) {
            system(ws2s(L"curl -l \"https://raw.githubusercontent.com/reedthorngag/device-lock/main/" + s2ws(i->c_str()) + L"\" --output " + s2ws(i->c_str())));
        }
    }

    BOOL update_password = false;
    fstream file;
    string password;
    file.open(L"bin\\password.txt",ios::in);
    if (file.is_open()) {
        getline(file,password);
        file.close();
        if (password=="") {
            cout << "no password in file, what password do you want? (remember it is stored as plain text): " << flush;
            cin >> password;
            file.open(L"bin\\password.txt",ios::out);
            file << password << flush;
            file.close();
        }
    } else {
        ofstream {L"password.txt"};
        cout << "what password do you want? (remember it is stored as plain text): " << flush;
        cin >> password;
        file.open(L"password.txt",ios::out);
        file << password << flush;
        file.close();
    }

    TCHAR path[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, path);

    system("start AutoHotkey mouselock.ahk > Nul");
    system("start AutoHotkey keyboardlock.ahk > Nul");
    system("start /b taskmanagerassasin.exe > Nul");
    system("devcon disable \"HID\\VID_04F3&UP:000D_U:0005\" > Nul");
    system("nircmd win hide class Shell_TrayWnd");
    system("schtasks /delete /TN \"DeviceLockHardReset\" /F > Nul");
    system(ws2s(L"schtasks /Create /TN \"DeviceLockHardReset\" /SC ONLOGON /TR \""+s2ws(path)+L"\\hard-reset.bat\" /RL HIGHEST"));

    system("echo (new ActiveXObject(\"WScript.Shell\")).AppActivate(\"lock.exe\"); > focus.js");
    system("cscript //nologo focus.js");
    system("del focus.js");

    system("cls");
    string password_input;
    cout << "enter password: " << flush;
    cin >> password_input;
    while (password_input!=password) {
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
    system("schtasks /delete /TN \"DeviceLockHardReset\" /F > Nul");

}