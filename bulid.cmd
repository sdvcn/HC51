@echo off
setlocal

set OUTDIR=.\bulid
set CHIP=STC12XX5624AD
set OBJ=.\bulid
set INC=.\include
set LIB=.\src\stc*.c

set HTC_WARN_FORMAT=WARNING: file %f; line %l; column %c; %s
set HTC_ERR_FORMAT=ERROR: file %f; line %l; column %c; %s

set ARGS= -Bs  -I%INC% --chip=%CHIP% --outdir=%OUTDIR% --objdir=%OBJ% %LIB%


rem c51 -C  %ARGS% %LIB% %1
c51 --time --summary=all %ARGS% %1
endlocal
