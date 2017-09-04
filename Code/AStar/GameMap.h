//
//  Map.h
//  AStar
//
//  Created by sunnior on 9/3/17.
//  Copyright (c) 2017 sunnior. All rights reserved.
//

#ifndef AStar_GameMap_h
#define AStar_GameMap_h

struct GamePoint
{
    int m_X;
    int m_Y;
};

struct GameMap
{
    static const int s_MaxBlocks = 128;
    static const int s_MaxSize = 32;

    int m_Height{0};
    int m_Width{0};
    int m_BlockNum{0};
    
    GamePoint m_Blocks[s_MaxBlocks]{};

    bool IsBlock(GamePoint gp)
    {
        for (int i = 0; i < m_BlockNum; ++i)
        {
            if (m_Blocks[i].m_X == gp.m_X && m_Blocks[i].m_Y == gp.m_Y)
            {
                return true;
            }
        }
        return false;
    }

	void AddBlock(GamePoint gp)
	{
		m_Blocks[m_BlockNum] = gp;
		++m_BlockNum;
	}
};

struct GamePath
{
    static const int s_MaxLength = 128;
    int m_Length{0};
    GamePoint m_Points[s_MaxLength]{};
    void PushPath(GamePoint gp) { m_Points[m_Length++] = gp;}
    void PopPath() {--m_Length;}
};

#endif
