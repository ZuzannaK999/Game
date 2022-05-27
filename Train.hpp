//
//  Train.hpp
//  GameFin
//
//  Created by Zuzanna Kapcia on 09/05/2022.
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
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

#define max_num_of_choices_T 3


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
