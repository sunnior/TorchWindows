#include "lua.hpp"

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int r = luaL_dofile(L, "practical3/simple_example.lua");
	if (r)
	{
		printf("%s\n", lua_tostring(L, -1));
	}

	lua_close(L);

}