@set InstallDir=..\..\..\Output\LuaJIT
if not exist %InstallDir% mkdir %InstallDir%
copy %1 %InstallDir%\lua5.1.lib