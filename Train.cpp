//
//  Train.cpp
//  GameFin
//
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
//

#include "Train.hpp"
#include "Game.hpp"

Train::Train(float widthT, float heightT)
{
   
        text[0].setString("Green");
        text[1].setString("Red");
        text[2].setString("Purple");

    text[0].setPosition(sf::Vector2f(widthT/2, heightT/(max_num_of_choices_T + 1)*1));
    text[1].setPosition(sf::Vector2f(widthT/2, heightT/(max_num_of_choices_T + 1)*2));
    text[2].setPosition(sf::Vector2f(widthT/2, heightT/(max_num_of_choices_T + 1)*3));
    
    Selected=0;
}

Train::~Train()
{
    
};
