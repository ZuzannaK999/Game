//
//  Level.cpp
//  GameFin
//
//

#include "Level.hpp"

Level::Level(float widthL, float heightL)
{
    text[0].setString("Easy");
    text[0].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices + 1)*1));
    
    text[1].setString("Medium");
    text[1].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices + 1)*2));
    
    text[2].setString("Hard");
    text[2].setPosition(sf::Vector2f(widthL/2, heightL/(max_num_of_choices + 1)*3));
    
    Selected=0;
}

Level::~Level()
{
    
};

