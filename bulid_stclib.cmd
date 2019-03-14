@echo off
setlocal

set OUTDIR=.\bulid
set CHIP=STC12XX5624AD
set OBJ=.\bulid
set INC=.\include

set HTC_WARN_FORMAT=WARNING: file %f; line %l; column %c; %s
set HTC_ERR_FORMAT=ERROR: file %f; line %l; column %c; %s

set ARGS= -S -Bs -I%INC% --time --summary=all --chip=%CHIP% --outdir=%OUTDIR% --objdir=%OBJ% --output=lib,lpp


c51 %ARGS% ./src/*.c
endlocal