#ifndef Wagons_hpp
#define Wagons_hpp
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
extern int gamemap[50][40];
class Wagons{
public:
 Wagons();
 Wagons(float wagonPosX, float wagonPosY);
 int wagonPosX;
 int wagonPosY;
 sf::Sprite wagons;
};
class trainBody{
public:
 trainBody();
 void addWagon();
 void deleteWagon();
 bool inGame;
 int numOfWagons;
 std::vector<Wagons>wagonsVec;
 int frontDirection(int direction, sf::Texture &train2Tex);
};
#endif /* Wagons_hpp */
