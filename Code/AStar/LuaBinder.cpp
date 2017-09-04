#include "LuaBinder.h"
#include "lua.hpp"
#include "GameMap.h"
#include "AStar.h"
#include <memory>

#define LUA_FILE_NAME "resource.lua"

static int userlua_create_game_map(lua_State* L)
{
	GameMap gameMap;
	
	lua_pushstring(L, "height");
	lua_gettable(L, -2);
	gameMap.m_Height = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	lua_pushstring(L, "width");
	lua_gettable(L, -2);
	gameMap.m_Width = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	lua_pushstring(L, "bits");
	lua_gettable(L, -2);

	for (int y = 0; y < gameMap.m_Height; ++y) {
		for (int x = 0; x < gameMap.m_Width; ++x) {
			lua_pushnumber(L, y*gameMap.m_Width + x + 1);
			lua_gettable(L, -2);
			int bit = (int)lua_tonumber(L, -1);
			lua_pop(L, 1);
			if (bit)
			{
				gameMap.AddBlock(GamePoint{ x, y });
			}
		}
	}

	GameMap* gameMapLua = (GameMap*)lua_newuserdata(L, sizeof(GameMap));
	std::memcpy(gameMapLua, &gameMap, sizeof(GameMap));

	return 1;
}

static int userlua_astar_algorithm(lua_State* L)
{
	GamePoint gpe, gps;
	int r = lua_istable(L, -1);
	lua_pushstring(L, "x");
	lua_gettable(L, -2);
	gpe.m_X = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	lua_pushstring(L, "y");
	lua_gettable(L, -2);
	gpe.m_Y = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	lua_pushstring(L, "x");
	lua_gettable(L, -3);
	gps.m_X = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	lua_pushstring(L, "y");
	lua_gettable(L, -3);
	gps.m_Y = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	GameMap* gameMap = (GameMap*)lua_touserdata(L, -3);

	GamePath gamePath = AStar().FindPath(*gameMap, gps, gpe);

	bool ifMove = false;
	if (gamePath.m_Length > 0)
	{
		ifMove = true;
	}
	lua_pushboolean(L, ifMove);
	return 1;
}

LuaBinder::LuaBinder()
{
	m_pLuaState = luaL_newstate();
	luaL_openlibs(m_pLuaState);
	lua_pushcfunction(m_pLuaState, userlua_create_game_map);
	lua_setglobal(m_pLuaState, "create_game_map");
	lua_pushcfunction(m_pLuaState, userlua_astar_algorithm);
	lua_setglobal(m_pLuaState, "astar_algorithm");
}

LuaBinder::~LuaBinder()
{
	lua_close(m_pLuaState);
}

void LuaBinder::Run()
{
	int r = luaL_dofile(m_pLuaState, LUA_FILE_NAME);
	if (r)
	{
		printf("%s\n", lua_tostring(m_pLuaState, -1));
	}
}

