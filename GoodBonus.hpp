#ifndef GoodBonus_hpp
#define GoodBonus_hpp
#include <stdio.h>
#include "Passengers.hpp"
#include <stdio.h>
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
extern int gamemap[50][40];
class GoodBonus
{
public:
 GoodBonus();
 sf::Sprite goodBonSpr;
 int goodBonPosX;
 int goodBonPosY;
 int GoodBon_picked = 0;
 void spawn();
 bool goodIsPicked(int x, int y);
};
#endif /* GoodBonus_hpp */
