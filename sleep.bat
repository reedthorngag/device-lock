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

cd "c:\code\security programs"

update.exe

start AutoHotkey keyboardlockdown.ahk
start taskmanagerkiller.exe

pnputil /disable-device /deviceid "HID\VID_04F3&UP:000D_U:0005" > Nul
pnputil /disable-device /deviceid "HID_DEVICE_SYSTEM_MOUSE" > Nul

:-getpassword
set /P password="enter password: "
if not [!password!]==[password] (
    echo error, wrong password
    timeout /t 5 > Nul
    GOTO -getpassword
)

taskkill /F /IM AutoHotkey.exe /T > Nul
taskkill /F /IM taskmanagerkiller.exe /T > Nul

pnputil /enable-device /deviceid "HID\VID_04F3&UP:000D_U:0005" > Nul
pnputil /enable-device /deviceid "HID_DEVICE_SYSTEM_MOUSE" > Nul