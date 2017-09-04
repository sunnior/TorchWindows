//
//  AStar.cpp
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#include "AStar.h"
#include <memory>
#include <cmath>

GamePath AStar::FindPath(GameMap gameMap, GamePoint gpStart, GamePoint gpEnd)
{
    memset(m_PassMarker, 0, GameMap::s_MaxSize*GameMap::s_MaxSize);
    m_SearchQueue.clear();
    SearchPoint sp;
    
    sp.m_Point = gpStart;
    sp.m_PCost = 0;
    sp.m_PassPath.PushPath(gpStart);
    
    m_SearchQueue.push_front(sp);
    m_PassMarker[sp.m_Point.m_Y][sp.m_Point.m_X] = true;
    
    while (!m_SearchQueue.empty())
    {
        
        SearchPoint psp = *m_SearchQueue.begin();
        m_SearchQueue.pop_front();
        int searchDir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i)
        {
            GamePoint gp{psp.m_Point.m_X + searchDir[i][0], psp.m_Point.m_Y + searchDir[i][1]};
            if (gp.m_X >= gameMap.m_Width || gp.m_Y >= gameMap.m_Height ||
                gp.m_X < 0 || gp.m_Y < 0 ||
                gameMap.IsBlock(gp) ||
                m_PassMarker[gp.m_Y][gp.m_X])
            {
                continue;
            }
            
            SearchPoint nsp;
            nsp.m_Point = gp;
            nsp.m_PassPath = psp.m_PassPath;
            nsp.m_PassPath.PushPath(nsp.m_Point);
            nsp.m_PCost = psp.m_PCost + 1;
            nsp.m_HCost = std::pow(std::pow(gpEnd.m_X - nsp.m_Point.m_X, 2) + std::pow(gpEnd.m_Y - nsp.m_Point.m_Y, 2), 0.5);
            m_PassMarker[nsp.m_Point.m_Y][nsp.m_Point.m_X] = true;
            
            if (nsp.m_Point.m_Y == gpEnd.m_Y && nsp.m_Point.m_X == gpEnd.m_X)
            {
                return nsp.m_PassPath;
            }
            
            auto it = m_SearchQueue.begin();
            while (it != m_SearchQueue.end())
            {
                if ((*it).m_PCost + (*it).m_HCost > nsp.m_HCost + nsp.m_PCost)
                {
                    break;
                }
                ++it;
            }
            
            m_SearchQueue.insert(it, nsp);
        }
            
    }
    
    return GamePath{};
}
