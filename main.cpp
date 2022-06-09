#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#include "Options.h"
#include "Sceneries.hpp"
#include <list>
#include "Train.hpp"
#include "Play.hpp"
#include "Level.hpp"
#include "Passengers.hpp"
#include "Wagons.hpp"
#include <cmath>
#include <limits>
#include <sstream>
#include "GoodBonus.hpp"
#include "ResourcePath.hpp"
#include "Music.hpp"
int gamemap[50][40];
int main(int, char const**)
{
    bool play = false;
    bool random = false;
    int score = 0;
    int max_score=0;
    int dire = 0;
    //time max
    int max;
    Clock clock;
    sf::Time timee;
    sf::RenderWindow MenuWindow(sf::VideoMode(800, 600), "MAIN MENU");
    MainMenu MainMenu(MenuWindow.getSize().x, MenuWindow.getSize().y);
    //main background
    sf::RectangleShape background;
    background.setSize(Vector2f(800,600));
    sf::Texture MainTex;
    MainTex.loadFromFile("main2.png");
    background.setTexture(&MainTex);
    //selective background
    sf::RectangleShape background2;
    background2.setSize(Vector2f(800,600));
    background2.setTexture(&MainTex);
    //first option
    sf::Texture desTex;
    if(!desTex.loadFromFile("desert.png"))
    {
        cout << "No texture found";
    }
    sf::Sprite desert;
    desert.setTexture(desTex);
    desert.setScale(0.5, 0.5);
    desert.setTextureRect(sf::IntRect(100,0, 500, 200));
    desert.setPosition(Vector2f(320,250));
    //second option
    sf::Texture islTex;
    if(!islTex.loadFromFile("sea.png"))
    {
        cout << "No texture found";
    }
    sf::Sprite island;
    island.setTexture(islTex);
    island.setScale(0.5, 0.5);
    island.setTextureRect(sf::IntRect(0,0, 500, 200));
    island.setPosition(Vector2f(320,450));
    //train sprite
    sf::Texture train2Tex;
    sf::Texture frontTex;
    if(!frontTex.loadFromFile("front.png"))
    {
        std::cout << "No texture found";
    }
    trainBody train2;
    Wagons front;
    front.wagons.setTexture(frontTex);
    front.wagons.setOrigin(24,24);
    front.wagons.setScale(1, 1);
    front.wagons.setRotation(180);
    train2.wagonsVec.push_back(front);
    //character sprite
    sf::Texture char1Tex;
    if(!char1Tex.loadFromFile("player.png"))
    {
        cout << "No texture found";
    }
    Passengers char1;
    char1.char1Spr.setScale(0.2, 0.2);
//    char1.char1Spr.setScale(1.5, 1.5);
    char1.char1Spr.setTexture(char1Tex);
    //bonuses
    sf::Texture goodBonTex;
    if(!goodBonTex.loadFromFile("Coin1.png"))
    {
        cout << "No texture found";
    }
    GoodBonus goodBon;
    goodBon.goodBonSpr.setTexture(goodBonTex);
    goodBon.goodBonSpr.setScale(1, 1);
//main font
    sf::Font font;
    if(!font.loadFromFile("PixelFont.ttf"))
    {
        cout << "No font found";
    }
    
    //texts in play window
    sf::Text text;
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setPosition(655, 550);
    //score
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(200, 550);
    scoreText.setString("0");
    //timer text
    Text textTimer("", font);
    textTimer.setPosition(10,10);
    textTimer.setFillColor(sf::Color::Black);
    //text in the end
    sf::Text endText;
    endText.setFont(font);
    //music
    sf::Music music;
    if (!music.openFromFile("Intro.ogg")) {
        return EXIT_FAILURE;
    }
    music.setLoop(true);
    music.play();
