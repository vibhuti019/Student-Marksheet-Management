@echo off

REM Gives Title To The Prompt
title Installer

REM Creates Required Directories
md Students
md SoftFiles


REM Compiles The Code
gcc -o ./SoftFiles/print Print_dic.c
gcc -o ./SoftFiles/addentries Add_Entries.c
gcc -o ./SoftFiles/view view_marksheet.c
gcc -o ./SoftFiles/main main.c
copy sprint.bat .\SoftFiles\sprint.bat

REM Create Shorcut To Start The Program
echo Set oWS = WScript.CreateObject("WScript.Shell") > CreateShortcut.vbs
echo sLinkFile = "%CD%\StuDBMS.lnk" >> CreateShortcut.vbs
echo Set oLink = oWS.CreateShortcut(sLinkFile) >> CreateShortcut.vbs
echo oLink.TargetPath = "%CD%\SoftFiles\main.exe" >> CreateShortcut.vbs
echo oLink.WorkingDirectory = "%CD%\SoftFiles" >> CreateShortcut.vbs
echo oLink.Save >> CreateShortcut.vbs
cscript CreateShortcut.vbs
del CreateShortcut.vbs


REM Deletes And Put Files In Required Directories
copy Print_dic.c .\SoftFiles\Print_dic.c
copy Add_Entries.c  .\SoftFiles\Add_Entries.c
copy view_marksheet.c  .\SoftFiles\view_marksheet.c
copy main.c  .\SoftFiles\main.c
copy Installer.bat .\SoftFiles\Installer.bat

REM Delete Files
del main.c
del Print_dic.c
del Add_Entries.c
del view_marksheet.c
del sprint.bat
del Installer.bat

echo Press Any Key To Run The Program
pause
echo Use StuDBMS Shortcut To Run Program
pause
