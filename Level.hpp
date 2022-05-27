//
//  Level.hpp
//  GameFin
//
//  Created by Zuzanna Kapcia on 16/05/2022.
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
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

#define max_num_of_choices_L 3


class Level : public Game
{
public:
    Level(float widthT, float heightT);
    ~Level();

    int LevelPressed() {
        return Selected;
    }
};
    


#endif /* Level_hpp */
