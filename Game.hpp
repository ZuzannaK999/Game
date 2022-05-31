//
//  Game.hpp
//  GameFin
//
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using namespace std;

#define max_num_of_choices 3


class Game
{
public:
    Game();
    ~Game();
    sf::Font font;
    sf::Text text[max_num_of_choices];
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int Selected;
   
};

#endif /* Game_hpp */
