#ifndef Passengers_hpp
#define Passengers_hpp
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
extern int gamemap[50][40];
class Passengers
{
public:
 Passengers();
 int charPosX;
 int charPosY;
 int char_picked = 0;
 void spawn();
 sf::Sprite char1Spr;
 bool isPicked(int x, int y);
};
#endif /* Passengers_hpp */
