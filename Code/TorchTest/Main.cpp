#include "lua.hpp"

extern "C" int luaopen_libtorch(lua_State *L);
extern "C" int luaopen_libsys(lua_State *L);
extern "C" int luaopen_libimage(lua_State *L);
extern "C" int luaopen_cjson(lua_State *l);
extern "C" int luaopen_libjpeg(lua_State *L);

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_libtorch(L);
	luaopen_libsys(L);
	luaopen_libimage(L);
	luaopen_cjson(L);
	luaopen_libjpeg(L);


	int r = luaL_dofile(L, "fast_neural_style/fast_neural_style.lua");
	if (r)
	{
		const char* ss = lua_tostring(L, -1);
		printf("%s\n", lua_tostring(L, -1));
	}
	while (true);

	lua_close(L);
}