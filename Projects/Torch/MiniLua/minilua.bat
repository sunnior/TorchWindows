@set Executable=%1
@set LuaJITPath=%2
@set DASM=%LuaJITPath%\dynasm\dynasm.lua
@set OutputFile=%LuaJITPath%\src\host\buildvm_arch.h
@set DASC=%LuaJITPath%\src\vm_x86.dasc

%Executable% %DASM% -LN -D WIN -D JIT -D FFI -D P64 -o %OutputFile% %DASC%