@echo off
setlocal

rem STC12XX5624AD
set OUTDIR=.\bulid
set CHIP=STC12X56
set INC=.\include

set HTC_WARN_FORMAT=WARNING: file %f; line %l; column %c; %s
set HTC_ERR_FORMAT=ERROR: file %f; line %l; column %c; %s

set ARGS= --runtime=none -I%INC% --chip=%CHIP% --outdir=%OUTDIR%  --output=lpp -Ostc12X56

c51 -S --echo %ARGS% ./src/stc12X56_*.c 
c51 --time --summary=all %ARGS% ./src/stc12X56_*.c 
endlocal
