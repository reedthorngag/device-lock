@echo off

devcon disable "HID\\VID_04F3&UP:000D_U:0005" > Nul
devcon enable "HID\\VID_04F3&UP:000D_U:0005" > Nul
nircmd win show class Shell_TrayWnd
schtasks /delete /TN "DeviceLockHardReset" /F > Nul
