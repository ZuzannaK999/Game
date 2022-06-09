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
     //main menu
    while (MenuWindow.isOpen())
    {
        sf::Event event;
        while (MenuWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                MenuWindow.close();
            }
            if(event.type == Event::KeyReleased)
            {
                 //choosing a main menu option(using the arrow keys)
                if(event.key.code == Keyboard::Up)
                {
                    MainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down)
                {
                    MainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return)
                {
                    RenderWindow PlayWindow(VideoMode(800,600), "GAME");
                    Play Play(PlayWindow.getSize().x, PlayWindow.getSize().y);
                    RenderWindow OptionWindow(VideoMode(800,600), "OPTIONS");
                    Options Options(OptionWindow.getSize().x, OptionWindow.getSize().y);
                    int m=MainMenu.MainMenuPressed();
                    if(m == 0)
                    {
                        while(OptionWindow.isOpen())
                        {
                            sf::Event OptionEvent;
                            while(OptionWindow.pollEvent(OptionEvent))
                            {
                                if(OptionEvent.type == Event::Closed)
                                {
                                    OptionWindow.close();
                                }
                                if(OptionEvent.type == Event::KeyReleased)
                                {
                                    if(OptionEvent.key.code == Keyboard::Up)
                                    {
                                        Options.MoveUp();
                                    }
                                    if(OptionEvent.key.code == Keyboard::Down)
                                    {
                                        Options.MoveDown();
                                    }
                                    if(OptionEvent.key.code == Keyboard::Return)
                                    {
                                        int o=Options.OptionPressed();
                                        //first option: scenery
                                        if(o == 0)
                                        {
                                            RenderWindow SceneryWindow(VideoMode(800,600), "SCENERIES");
                                            Sceneries Sceneries(SceneryWindow.getSize().x, SceneryWindow.getSize().y);
                                            while(SceneryWindow.isOpen())
                                            {
                                                sf::Event SceneryEvent;
                                                while(SceneryWindow.pollEvent(SceneryEvent))
                                                {
                                                    if(SceneryEvent.type == Event::Closed)
                                                    {
                                                        SceneryWindow.close();
                                                    }
                                                    if(SceneryEvent.type == Event::KeyReleased)
                                                    {
                                                        if(SceneryEvent.key.code == Keyboard::Up)
                                                        {
                                                            Sceneries.MoveUpS();
                                                        }
                                                        if(SceneryEvent.key.code == Keyboard::Down)
                                                        {
                                                            Sceneries.MoveDownS();
                                                        }
                                                        if(SceneryEvent.key.code == Keyboard::Return)
                                                        {
                                                            int s = Sceneries.SceneryPressed();
                                                            //first scenery: desert
                                                            if(s == 0)
                                                            {
                                                                background2.setTexture(&desTex);
                                                            }
                                                            //second scenery: sea
                                                            if(s == 1)
                                                            {
                                                                background2.setTexture(&islTex);
                                                            }
                                                        }
                                                        if(SceneryEvent.key.code == Keyboard::Escape)
                                                        {
                                                            SceneryWindow.close();
                                                        }
                                                     }
                                                }
                                                SceneryWindow.clear();
                                                SceneryWindow.draw(background);
                                                Sceneries.drawS(SceneryWindow);
                                                SceneryWindow.display();
                                             }
                                        }
                                         if(o == 1)
                                        {
                                            //second option: color of the train
                                          RenderWindow TrainWindow(VideoMode(800,600), "TRAIN");
                                          Train Train(TrainWindow.getSize().x, TrainWindow.getSize().y);
                                            while(TrainWindow.isOpen())
                                            {
                                                sf::Event TrainEvent;
                                                while(TrainWindow.pollEvent(TrainEvent))
                                                {
                                                    if(TrainEvent.type == Event::Closed)
                                                    {
                                                        TrainWindow.close();
                                                    }
                                                    if(TrainEvent.type == Event::KeyReleased)
                                                    {
                                                        if(TrainEvent.key.code == Keyboard::Up)
                                                        {
                                                            Train.MoveUp();
                                                        }
                                                        if(TrainEvent.key.code == Keyboard::Down)
                                                        {
                                                            Train.MoveDown();
                                                        }
                                                        int t=Train.TrainPressed();
                                                        if(t==1)
                                                        {
                                                            front.wagons.setColor(sf::Color::Red);
                                                        }
                                                        if(t==2)
                                                        {
                                                            front.wagons.setColor(sf::Color::Magenta);
                                                        }
                                                        if(TrainEvent.key.code == Keyboard::Escape)
                                                        {
                                                            TrainWindow.close();
                                                        }
                                                     }
                                                }
                                                TrainWindow.clear();
                                                TrainWindow.draw(background);
                                                Train.draw(TrainWindow);
                                                TrainWindow.display();
                                            }
                                        }
                                      //third option: level of difficulty
                                        if(o == 2)
                                       {
                                         RenderWindow LevelWindow(VideoMode(800,600), "LEVEL");
                                         Level Level(LevelWindow.getSize().x, LevelWindow.getSize().y);
                                           while(LevelWindow.isOpen())
                                           {
                                               sf::Event LevelEvent;
                                               while(LevelWindow.pollEvent(LevelEvent))
                                               {
                                                   if(LevelEvent.type == Event::Closed)
                                                   {
                                                       LevelWindow.close();
                                                   }
                                                   if(LevelEvent.type == Event::KeyReleased)
                                                   {
                                                       if(LevelEvent.key.code == Keyboard::Up)
                                                       {
                                                           Level.MoveUp();
                                                       }
                                                       if(LevelEvent.key.code == Keyboard::Down)
                                                       {
                                                           Level.MoveDown();
                                                       }
                                                       if(LevelEvent.key.code == Keyboard::Escape)
                                                       {
                                                           LevelWindow.close();
                                                       }
                                                    }
                                                   int i = Level.LevelPressed();
                                                   if(i==0)
                                                   {
                                                       text.setString("EASY");
                                                       max=40;
                                                       max_score=3;
                                                   }
                                                   if(i==1)
                                                   {
                                                       text.setString("MEDIUM");
                                                       max=25;
                                                       max_score=4;
                                                   }
                                                   if(i==2)
                                                   {
                                                       text.setString("HARD");
                                                       max=15;
                                                       max_score=5;
                                                   }
                                               }
                                               LevelWindow.clear();
                                               LevelWindow.draw(background);
                                               Level.draw(LevelWindow);
                                               LevelWindow.display();
                                           }
                                       }
                                    }
                                    if(OptionEvent.key.code == Keyboard::Escape)
                                    {
                                        OptionWindow.close();
                                    }
                                }
                              }
                            OptionWindow.clear();
                            OptionWindow.draw(background);
                            Options.draw(OptionWindow);
                            OptionWindow.display();
                          }
                     }
