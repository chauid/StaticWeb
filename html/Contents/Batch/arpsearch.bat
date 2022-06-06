@echo off
chcp 65001>nul
setlocal ENABLEDELAYEDEXPANSION
netsh interface ipv4 show address>getGateway.txt
find "Default Gateway" getGateway.txt >nul
if %errorlevel% equ 0 (
 for /f "tokens=3 skip=1" %%i in ('find "Default Gateway" getGateway.txt') do set gateway=%%i
) else (
 echo Error occured in get Gateway IP & pause>nul
)
del getGateway.txt
set subnet=%gateway:~0,12%
if exist ping.txt del ping.txt
for /l %%i in (1,1,255) do (for /f "tokens=* skip=5" %%k in ('ping !subnet!%%i -n 1 -w 500') do echo !subnet!%%i %%k & break) >>ping.txt & cls &echo (%%i/255)
if exist getHost.txt del getHost.txt
echo Pinging...
for /f "tokens=1,2" %%i in (ping.txt) do if %%j equ Approximate (ping -a %%i -n 1 -w 500 >> getHost.txt)

if exist hostttl.txt del hostttl.txt
for /f "tokens=2 skip=2" %%i in ('find "Pinging" getHost.txt') do set /a count+=1
for /f "tokens=2 skip=2" %%i in ('find "Pinging" getHost.txt') do echo %%i >> hostttl.txt
for /f "tokens=6" %%i in ('find "TTL" getHost.txt') do echo %%i >>hostttl.txt
del getHost.txt
set /a count*=2
echo %count%
pause