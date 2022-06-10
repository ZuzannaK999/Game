#pragma once
#ifndef Sceneries_hpp
#define Sceneries_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace sf;
#define max_num_of_choices_S 2
class Sceneries : public Game
{
public:
 Sceneries(float width, float height);
 ~Sceneries();
 void drawS(sf::RenderWindow &window);
 void MoveUpS();
 void MoveDownS();
 int SceneryPressed() {
 return SelectedScenery;
 }

private:

 sf::Font fontS;
 sf::Text textS[max_num_of_choices];
 int SelectedScenery;
};

#endif /* Sceneries_hpp */
