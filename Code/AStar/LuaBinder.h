//
//  lua_bind.h
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#ifndef __LUABINDER_H__
#define __LUABINDER_H__

#include "GameMap.h"

class LuaBinder
{
public:
	LuaBinder();
	~LuaBinder();

	void Run();
private:
	struct lua_State* m_pLuaState{nullptr};
};
#endif
