//
//  Options.cpp
//  GameFin
//
//

//#include <stdio.h>
#include "Options.h"
#include "Game.hpp"

Options::Options(float widthO, float heightO)
{
    text[0].setString("Sceneries");
    text[0].setPosition(sf::Vector2f(widthO/2, heightO/(max_num_of_choices + 1)*1));
   
    text[1].setString("Train");
    text[1].setPosition(sf::Vector2f(widthO/2, heightO/(max_num_of_choices + 1)*2));
    
    text[2].setString("Level");
    text[2].setPosition(sf::Vector2f(widthO/2, heightO/(max_num_of_choices + 1)*3));
    
    Selected=0;
}

Options::~Options()
{
    
};

