//
//  MainMenu.h
//  GameFin
//
//

#ifndef MainMenu_h
#define MainMenu_h
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
using namespace sf;
using namespace std;

#define max_num_of_choices 3

class MainMenu : public Game
{
public:
    MainMenu(float width, float height);
    ~MainMenu();
    int GetSelectedOption()
    {
        return Selected;
    }
    int MainMenuPressed() {
        return Selected;
    }
};



#endif /* MainMenu_h */
