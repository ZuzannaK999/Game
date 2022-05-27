//
//  Level.cpp
//  GameFin
//
//  Created by Zuzanna Kapcia on 16/05/2022.
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
//

#include "Level.hpp"

Level::Level(float widthL, float heightL)
{
    text[0].setString("Easy");
    text[0].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices_L + 1)*1));
    
    text[1].setString("Medium");
    text[1].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices_L + 1)*2));
    
    text[2].setString("Hard");
    text[2].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices_L + 1)*3));
    
    Selected=0;
}

Level::~Level()
{
    
};

