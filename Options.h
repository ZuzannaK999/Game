//
//  Options.h
//  GameFin
//
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
