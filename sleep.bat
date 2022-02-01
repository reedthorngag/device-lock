::[Bat To Exe Converter]
::
::YAwzoRdxOk+EWAnk
::fBw5plQjdG8=
::YAwzuBVtJxjWCl3EqQJgSA==
::ZR4luwNxJguZRRnk
::Yhs/ulQjdF+5
::cxAkpRVqdFKZSjk=
::cBs/ulQjdF+5
::ZR41oxFsdFKZSDk=
::eBoioBt6dFKZSDk=
::cRo6pxp7LAbNWATEpCI=
::egkzugNsPRvcWATEpCI=
::dAsiuh18IRvcCxnZtBJQ
::cRYluBh/LU+EWAnk
::YxY4rhs+aU+JeA==
::cxY6rQJ7JhzQF1fEqQJQ
::ZQ05rAF9IBncCkqN+0xwdVs0
::ZQ05rAF9IAHYFVzEqQJQ
::eg0/rx1wNQPfEVWB+kM9LVsJDGQ=
::fBEirQZwNQPfEVWB+kM9LVsJDGQ=
::cRolqwZ3JBvQF1fEqQJQ
::dhA7uBVwLU+EWDk=
::YQ03rBFzNR3SWATElA==
::dhAmsQZ3MwfNWATElA==
::ZQ0/vhVqMQ3MEVWAtB9wSA==
::Zg8zqx1/OA3MEVWAtB9wSA==
::dhA7pRFwIByZRRnk
::Zh4grVQjdCyDJHqL8EcMOx5XWRaLKHL6FqcT7/r64vm7sUEYUfJxfZfeug==
::YB416Ek+ZW8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off

:: must be run as admin

setlocal enableDelayedExpansion

::update.exe

if not exist devcon.exe (
    curl -l "https://raw.githubusercontent.com/reedthorngag/computer-lock/main/devcon.exe" --output devcon.exe
)
if not exist mouselock.ahk (
    curl -l "https://raw.githubusercontent.com/reedthorngag/computer-lock/main/mouselock.ahk" --output mouselock.ahk
)
if not exist keyboardlock.ahk (
    curl -l "https://raw.githubusercontent.com/reedthorngag/computer-lock/main/keyboardlock.ahk" --output keyboardlock.ahk
)
if not exist taskmanagerassasin.exe (
    curl -l "https://raw.githubusercontent.com/reedthorngag/computer-lock/main/taskmanagerassasin.exe" --output taskmanagerassasin.exe
)

start AutoHotkey keyboardlock.ahk
start AutoHotkey mouselock.ahk
start taskmanagerkiller.exe

devcon.exe disable "HID\VID_04F3&UP:000D_U:0005"

:-getpassword
cls
set /P password="enter password: "
if not [!password!]==[password] (
    echo wrong password
    timeout /t 3
    GOTO -getpassword
)

taskkill /F /IM AutoHotkey.exe /T > Nul
taskkill /F /IM taskmanagerassasin.exe /T > Nul

devcon.exe enable "HID\VID_04F3&UP:000D_U:0005"