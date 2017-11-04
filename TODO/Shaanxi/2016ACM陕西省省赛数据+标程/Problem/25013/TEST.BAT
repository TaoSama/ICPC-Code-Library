@echo off

echo -----Start to Run-----
g++ std.cpp -O3 -o std.exe
set starttime=%time%
std
set endtime=%time%
set /a t1 = %endtime:~6,2% - %starttime:~6,2%
set /a t2 = %endtime:~9,2% - %starttime:~9,2%
if %t2% lss 0 set /a t2 += 100 & set /a t1 -= 1
if %t1% lss 0 set /a t1 += 60
if %t2% geq 10 (echo Runtime:%t1%.%t2%s) else echo Runtime:%t1%.0%t2%s

fc test out

pause
:end
