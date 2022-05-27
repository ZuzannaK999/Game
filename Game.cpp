//
//  Game.cpp
//  GameFin
//
//  Created by Zuzanna Kapcia on 26/05/2022.
//  Copyright © 2022 Zuzanna Kapcia. All rights reserved.
//

#include "Game.hpp"


Game::Game()
{
    if(!font.loadFromFile("PixelFont.ttf"))
    {
        cout << "No font found";
    }
    
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Red);
    
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
}

Game::~Game()
{
};

void Game::draw(sf::RenderWindow &window)
{
    for(int i=0; i< max_num_of_choices; i++)
    {
        window.draw(text[i]);
    }
}

void Game::MoveUp()
{
    if(Selected - 1 >= 0)
    {
        text[Selected].setFillColor(sf::Color::White);
        Selected--;
        text[Selected].setFillColor(sf::Color::Red);
    }
}
    
void Game::MoveDown()
{
    if(Selected + 1 < max_num_of_choices)
    {
        text[Selected].setFillColor(sf::Color::White);
        Selected++;
        text[Selected].setFillColor(sf::Color::Red);
    }
}


