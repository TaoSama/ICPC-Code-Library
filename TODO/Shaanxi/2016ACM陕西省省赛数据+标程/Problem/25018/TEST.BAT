@echo off

echo -----Start to Makedata-----
g++ CountingStar-makedata.cpp -o CountingStar-makedata.exe
CountingStar-makedata
echo -----Makedata End-----

echo -----Start to Run CountingStar-----
g++ CountingStar.cpp -o CountingStar.exe
set starttime=%time%
CountingStar
set endtime=%time%
set /a t1 = %endtime:~6,2% - %starttime:~6,2%
set /a t2 = %endtime:~9,2% - %starttime:~9,2%
if %t2% lss 0 set /a t2 += 100 & set /a t1 -= 1
if %t1% lss 0 set /a t1 += 60
if %t2% geq 10 (echo Runtime:%t1%.%t2%s) else echo Runtime:%t1%.0%t2%s

echo -----Start to Run CountingStar-duipai -----
g++ CountingStar-duipai.cpp -o CountingStar-duipai.exe
set starttime=%time%
CountingStar-duipai
set endtime=%time%
set /a t1 = %endtime:~6,2% - %starttime:~6,2%
set /a t2 = %endtime:~9,2% - %starttime:~9,2%
if %t2% lss 0 set /a t2 += 100 & set /a t1 -= 1
if %t1% lss 0 set /a t1 += 60
if %t2% geq 10 (echo Runtime:%t1%.%t2%s) else echo Runtime:%t1%.0%t2%s

fc result result-duipai

pause
:end
