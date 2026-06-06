@ECHO OFF
REM set to where Ditial Mars C++ with STLPort and DOS 16 libraries is installed
REM see https://www.digitalmars.com/download/freecompiler.html for details
SET DMC=c:\tools\dm857c


if not exist OUTDMC mkdir OUTDMC
%DMC%\bin\dmc -Isrc -2 -mt -D__WATCOMC__ src\jpatch.cpp -c -oOUTDMC\jpatch.obj
%DMC%\bin\link OUTDMC\jpatch.obj,OUTDMC\jpatcht.exe /EXETYPE:DOS /STACK:1024 
