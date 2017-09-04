//
//  lua_bind.cpp
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#include "lua_bind.h"
#include <lua.hpp>

struct LuaBinderImpl
{
    lua_State* m_LuaState;
};

LuaBinder::LuaBinder()
{
    m_impl = new LuaBinderImpl;
    m_impl->m_LuaState = luaL_newstate();
}

LuaBinder::~LuaBinder()
{
    delete m_impl;
}

void LuaBinder::Run()
{
    luaL_openlibs(m_impl->m_LuaState);
    int error = luaL_dofile(m_impl->m_LuaState, "resource.lua");
    if (error)
    {
        printf("%s\n", lua_tostring(m_impl->m_LuaState, -1));
    }
}

char LuaBinder::getCommand()
{
    return 'c';
}

GameMap  LuaBinder::getGameMap()
{
    const int map_input[16][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        
    };

    GameMap gameMap;
    gameMap.m_Height = 16;
    gameMap.m_Width = 16;

    for (int y = 0; y < 16; ++y)
    {
        for (int x = 0; x < 16; ++x)
        {
            if (map_input[y][x] == 1)
            {
                gameMap.m_Blocks[gameMap.m_BlockNum].m_Y = y;
                gameMap.m_Blocks[gameMap.m_BlockNum].m_X = x;
                ++gameMap.m_BlockNum;
            }
        }
    }
    
    return gameMap;
}

GamePoint  LuaBinder::getStartPoint()
{
    return GamePoint{0, 15};
}

GamePoint  LuaBinder::getEndPoint()
{
    return GamePoint{15, 15};
}

void  LuaBinder::printPath(GamePath path)
{
    /*
    std::cout << "***************" << std::endl;
    
    for (int i = 0; i < path.m_Length; ++i)
    {
        std::cout << path.m_Points[i].m_X << " " << path.m_Points[i].m_Y << std::endl;
    }
    
    std::cout << "***************" << std::endl;
     */
}

