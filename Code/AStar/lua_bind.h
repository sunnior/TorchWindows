//
//  lua_bind.h
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#ifndef AStar_lua_bind_h
#define AStar_lua_bind_h

#include "GameMap.h"

class LuaBinder
{
public:
    LuaBinder();
    ~LuaBinder();
    
    void Run();
    
private:
    GameMap getGameMap();
    GamePoint getStartPoint();
    GamePoint getEndPoint();
    void printPath(GamePath path);
    char getCommand();
    
private:
    struct LuaBinderImpl* m_impl;
};
#endif
