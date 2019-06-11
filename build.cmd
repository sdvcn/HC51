@echo off
setlocal

set OUTDIR=.\bulid
set CHIP=STC8A8K60S4A12
set OBJ=.\bulid
set INC=.\include
set OUTFILE=8051.hex
set LIB=.\src\*.c .\src\ext\*.c 

set HTC_WARN_FORMAT=WARNING: file %f; line %l; column %c; %s
set HTC_ERR_FORMAT=ERROR: file %f; line %l; column %c; %s
set DEFINE=-DDEBUG
set ARGS=-M --OPT=all %DEFINE% -Bs  -I%INC% --chip=%CHIP% --outdir=%OUTDIR% --objdir=%OBJ% %LIB% -O%OUTFILE%

echo //////////////////////////////////////////////////////////////////////
echo ChipInfo = %CHIP%
echo //////////////////////////////////////////////////////////////////////



rem c51 -C  %ARGS% %LIB% %1
IF %ERRORLEVEL% NEQ 0 goto enderr
c51 -S -Q -P %ARGS% %*
IF %ERRORLEVEL% NEQ 0 goto enderr
c51 --time --summary=all %ARGS% %*
IF %ERRORLEVEL% NEQ 0 goto enderr
goto gend
:enderr
echo //////////////////////////////////////////////////////////////////////
echo ERROT %ERRORLEVEL%
echo //////////////////////////////////////////////////////////////////////
:gend

endlocal
