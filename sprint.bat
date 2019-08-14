@echo off
cls
color E4
cd %temp%
type tStu.bin
echo **************************************************************************** >> tStu.bin
echo.
echo *                                                                          *
echo *                   Save The File And Close Notepad                        *
echo *                                                                          *
echo *                                                                          *
echo ****************************************************************************
ren tStu.bin tStu.txt
start /b /wait notepad tStu.txt
del tStu.txt
pause
cd %appdata%/StuDBMS/SoftFiles
print