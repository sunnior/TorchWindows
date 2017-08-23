@set Executable=%1
@set LuaJITPath=..\..\..\Code\LuaJIT-2.1.0-beta3
@set SrcPath=%LuaJITPath%\src
@set ALL_LIB=%SrcPath%\lib_base.c %SrcPath%\lib_math.c %SrcPath%\lib_bit.c %SrcPath%\lib_string.c %SrcPath%\lib_table.c %SrcPath%\lib_io.c %SrcPath%\lib_os.c %SrcPath%\lib_package.c %SrcPath%\lib_debug.c %SrcPath%\lib_jit.c %SrcPath%\lib_ffi.c

::%Executable% -m peobj -o lj_vm.obj
%Executable% -m bcdef -o %SrcPath%\lj_bcdef.h %ALL_LIB%
%Executable% -m ffdef -o  %SrcPath%\lj_ffdef.h %ALL_LIB%
%Executable% -m libdef -o %SrcPath%\lj_libdef.h %ALL_LIB%
%Executable% -m recdef -o %SrcPath%\lj_recdef.h %ALL_LIB%
%Executable% -m vmdef -o %SrcPath%\vmdef.lua %ALL_LIB%
%Executable% -m folddef -o %SrcPath%\lj_folddef.h %SrcPath%\lj_opt_fold.c

