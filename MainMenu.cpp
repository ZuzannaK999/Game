//
//  MainMenu.cpp
//  GameFin
//
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
//

//#include <stdio.h>
#include "MainMenu.h"
#include "Game.hpp"


MainMenu::MainMenu(float width, float height)
{
    text[0].setString("Options");
    text[0].setPosition(sf::Vector2f(width/2, height/(max_num_of_choices + 1)*1));
    
    text[1].setString("Play");
    text[1].setPosition(sf::Vector2f(width/2, height/(max_num_of_choices + 1)*2));
    
    text[2].setString("Exit");
    text[2].setPosition(sf::Vector2f(width/2, height/(max_num_of_choices + 1)*3));
    
    Selected=0;
}

MainMenu::~MainMenu()
{
    
};


