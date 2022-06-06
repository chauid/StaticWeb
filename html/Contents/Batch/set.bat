@echo off
set /p a=변수 a : 
echo %a%
set /p b=변수 b : 
echo %b%
set /p c=변수 c : 
echo %c%
set /a d=a+b+c
echo a=%a%, b=%b%, c=%c%, d=a+b+c=%d%
echo.
set /a a=a
set /a b=b
set /a c=c
if %a%==0 (echo a는 0또는 문자열입니다.) else (echo a는 숫자입니다.)
if %b%==0 (echo b는 0또는 문자열입니다.) else (echo b는 숫자입니다.)
if %c%==0 (echo c는 0또는 문자열입니다.) else (echo c는 숫자입니다.)
pause