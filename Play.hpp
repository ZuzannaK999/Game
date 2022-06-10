#ifndef Play_hpp
#define Play_hpp
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

class Play : public Game
{
public:
    Play(float widthP, float heightP);
    ~Play();
    void drawP(sf::RenderWindow &window);
private:
    sf::Text textP[2];
};
    

#endif /* Play_hpp */
