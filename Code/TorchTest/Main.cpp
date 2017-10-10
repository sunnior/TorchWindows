#include "lua.hpp"

extern "C" int luaopen_libtorch(lua_State *L);
extern "C" int luaopen_libsys(lua_State *L);
extern "C" int luaopen_libimage(lua_State *L);
extern "C" int luaopen_cjson(lua_State *l);

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_libtorch(L);
	luaopen_libsys(L);
	luaopen_libimage(L);
	luaopen_cjson(L);

	int r = luaL_dofile(L, "fast_neural_style/fast_neural_style.lua");
	if (r)
	{
		const char* ss = lua_tostring(L, -1);
		printf("%s\n", lua_tostring(L, -1));
	}

	lua_close(L);

}