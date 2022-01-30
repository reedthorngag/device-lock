::[Bat To Exe Converter]
::
::fBE1pAF6MU+EWHreyGE/LB5oXwGBKXmzEqxc+Pr06PiGr14hR+46fZ+V36yLQA==
::fBE1pAF6MU+EWHreyGE/LB5oXwGBKXmzEqxc+Pr06PiGr14hQOMsc4La1LWJJfIY40nocIRj02Jf+A==
::fBE1pAF6MU+EWHreyGE/LB5oXwGBKXmzEqxc+Pr06PiGr14hX+cmeoDayLCCL+MY7krze9gs3nE6
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
::Zh4grVQjdCyDJHqL8EcMOx5XWRaLKHL6FqcT7/r64vm7q0MOQOMzdIrJlLGWJYA=
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off

if exist "%cd%\computer lock" (
  echo computer lock is already installed!
  pause
  exit
)

mkdir "%cd%\computer lock"

xcopy /Y sleep.exe "%cd%\sleep.exe"
xcopy /Y keyboardlockdown.ahk "%cd%\keyboardlockdown.ahk"
xcopy /Y taskmanagerkiller.exe "%cd%\taskmanagerkiller.exe"

echo finished! run sleep.exe to lock your computer
pause