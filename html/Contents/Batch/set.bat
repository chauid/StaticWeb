@echo off
set /p a=���� a : 
echo %a%
set /p b=���� b : 
echo %b%
set /p c=���� c : 
echo %c%
set /a d=a+b+c
echo a=%a%, b=%b%, c=%c%, d=a+b+c=%d%
echo.
set /a a=a
set /a b=b
set /a c=c
if %a%==0 (echo a�� 0�Ǵ� ���ڿ��Դϴ�.) else (echo a�� �����Դϴ�.)
if %b%==0 (echo b�� 0�Ǵ� ���ڿ��Դϴ�.) else (echo b�� �����Դϴ�.)
if %c%==0 (echo c�� 0�Ǵ� ���ڿ��Դϴ�.) else (echo c�� �����Դϴ�.)
pause