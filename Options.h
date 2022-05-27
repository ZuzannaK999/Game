//
//  Options.h
//  GameFin
//
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
//

#ifndef Options_h
#define Options_h
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>
using namespace sf;
using namespace std;

#define max_num_of_choices_O 3

class Options : public Game
{
public:
    Options(float widthO, float heightO);
    ~Options();
    
    int OptionPressed() {
        return Selected;
    }
};
    
    


#endif /* Options_h */
