@echo off
REM This Is A Auxillary File For view.exe

REM Clear THe Screen
cls

REM Change The Color
color E4

REM Creating Temp File And Viewing It
cd %temp%
type tStu.bin
echo **************************************************************************** >> tStu.bin
echo.
echo *                                                                          *
echo *                   Save The File And Close Notepad                        *
echo *                                                                          *
echo *                                                                          *
echo ****************************************************************************

REM Create Temp File
ren tStu.bin tStu.txt

REM Start Notepad And Halt The Executer
start /b /wait notepad tStu.txt

REM Create Temp File
del tStu.txt

REM Exit
pause
cd %appdata%/StuDBMS/SoftFiles

REM Open Print Again
print
