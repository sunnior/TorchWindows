#include "lua.hpp"

extern "C" int luaopen_libtorch(lua_State *L);
extern "C" int luaopen_libsys(lua_State *L);

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_libtorch(L);
	luaopen_libsys(L);

	int r = luaL_dofile(L, "practical3/simple_example.lua");
	if (r)
	{
		printf("%s\n", lua_tostring(L, -1));
	}

	lua_close(L);

}