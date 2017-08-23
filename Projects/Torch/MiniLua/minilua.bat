@set Executable=%1
@set LuaJITPath=..\..\..\Code\LuaJIT-2.1.0-beta3
@set DASM=%LuaJITPath%\dynasm\dynasm.lua
@set OutputFile=%LuaJITPath%\src\host\buildvm_arch.h
@set DASC=%LuaJITPath%\src\vm_x64.dasc

%Executable% %DASM% -LN -D WIN -D JIT -D FFI -o %OutputFile% %DASC%