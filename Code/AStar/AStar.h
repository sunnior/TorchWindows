//
//  AStar.h
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#ifndef AStar_AStar_h
#define AStar_AStar_h

#include "GameMap.h"
#include <list>

class AStar{
public:
    GamePath FindPath(GameMap gameMap, GamePoint gpStart, GamePoint gpEnd);
    
private:
    struct SearchPoint
    {
        GamePoint m_Point;
        int m_PCost{0};
        int m_HCost{0};
        GamePath m_PassPath;
    };
    
private:
    bool m_PassMarker[GameMap::s_MaxSize][GameMap::s_MaxSize]{};
    
    std::list<SearchPoint> m_SearchQueue;
};

#endif
