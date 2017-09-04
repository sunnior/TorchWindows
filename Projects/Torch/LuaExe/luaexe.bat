@set InstallDir=..\..\..\Output\LuaJIT
if not exist %InstallDir% mkdir %InstallDir%
copy %1 %InstallDir%\luajit.exe