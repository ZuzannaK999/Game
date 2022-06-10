//
//  Level.hpp
//  GameFin
//
//

#ifndef Level_hpp
#define Level_hpp

#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include <stdio.h>
using namespace std;

class Level : public Game
{
public:
    Level(float widthL, float heightL);
    ~Level();

    int LevelPressed() {
        return Selected;
    }
};
    


#endif /* Level_hpp */
