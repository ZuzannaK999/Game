//
//  Train.hpp
//  GameFin
//
//

#ifndef Train_hpp
#define Train_hpp
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include <stdio.h>
using namespace std;


class Train : public Game
{
public:
    Train(float widthT, float heightT);
    ~Train();
    void drawT(sf::RenderWindow &window);
    int TrainPressed() {
        return Selected;
    }

};
    

#endif /* Train_hpp */
