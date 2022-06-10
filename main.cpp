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
    char1.char1Spr.setTexture(char1Tex);
    //bonus sprite
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
    //score text
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
                       if(m == 1)
                    {
                        PlayWindow.setFramerateLimit(60);
                           srand(time(NULL));
                           Clock clockk;
                           Time time;
                           stringstream ss;
                           int s=0;
                           int g=0;
                           int m=0;
                            while(PlayWindow.isOpen())
                        {
                            if(play == false)
                                    {
                                        for(int i = 0; i < 50; i++)
                                        {
                                        for(int j = 0; j < 40; j++)
                                                gamemap[i][j] = 0;
                                        }
                                        dire=0;
                                        train2.numOfWagons = 1;
                                        train2.inGame = true;
                                        train2.wagonsVec.clear();
                                        train2.wagonsVec.push_back(front);
                                        train2.wagonsVec[0].wagons.setRotation(180);
                                        train2.wagonsVec[0].wagons.setOrigin(24,24);
                                        char1.spawn();
                                        goodBon.spawn();
                                        goodBon.GoodBon_picked=0;
                                        play = true;
                                    }
                         //timer
                            ss.str("");
                            time=clockk.getElapsedTime();
                            s=time.asMilliseconds();
                            g=s/1000;
                            m=(s-(g*1000))/60;
                            s=s-(g*1000+m*60);
                     
                            if(g<10)
                            {
                              ss<<"0"<<g;
                            }
                            else
                            {
                               ss<<g;
                            }
                            if(m<10)
                            {
                                ss<<":"<<"0"<<m;
                            }
                            else
                            {
                                ss<<":"<<m;
                            }
                            if(s<10)
                            {
                                ss<<":"<<"0"<<s;
                            }
                            else
                            {
                                ss<<":"<<s;
                            }
                            if(g>max)
                            {
                                RenderWindow OverWindow(VideoMode(800,600), "THE END");
                                endText.setString("GAME OVER!");
                                endText.setCharacterSize(70);
                                endText.setPosition(200,250);
                                endText.setFillColor(sf::Color::Black);
                                while(OverWindow.isOpen())
                                {
                                    sf::Event eve;
                                    while(OverWindow.pollEvent(eve))
                                    {
                                        if(eve.type == Event::Closed)
                                        {
                                            OverWindow.close();
                                        }
                                        if(eve.type == Event::KeyPressed)
                                        {
                                            if(eve.key.code==Keyboard::Escape)
                                            {
                                            OverWindow.close();
                                            }
                                        }
                                    }
                                OverWindow.clear();
                                OverWindow.draw(background2);
                                OverWindow.draw(endText);
                                OverWindow.display();
                                PlayWindow.close();
                                MenuWindow.close();
                                }
                            }
                            textTimer.setString(ss.str());
                            PlayWindow.setFramerateLimit(60);
                            PlayWindow.clear();
                            timee=clock.getElapsedTime();


                           sf::Event PlayEvent;
                            while(PlayWindow.pollEvent(PlayEvent))
                            {
                                if(PlayEvent.type == Event::Closed)
                                {
                                    PlayWindow.close();
                                }
                                if(PlayEvent.type == Event::KeyPressed)
                                {
                                                    if(dire != 1 && dire != 2)
                                                    {
                                                        if(PlayEvent.key.code == sf::Keyboard::Up)
                                                        {
                                                            dire = 1;
                                                            train2.wagonsVec[0].wagons.setRotation(0);
                                                            train2.wagonsVec[0].wagons.setOrigin(0,0);
                                                        }
                                                        else if(PlayEvent.key.code == sf::Keyboard::Down)
                                                        {
                                                            dire = 2;
                                                            train2.wagonsVec[0].wagons.setRotation(180);
                                                            train2.wagonsVec[0].wagons.setOrigin(24,24);
                                                        }
                                                    }
                                                    if(dire != 3 && dire != 4)
                                                    {
                                                        if(PlayEvent.key.code == sf::Keyboard::Right)
                                                        {
                                                            dire = 3;
                                                            train2.wagonsVec[0].wagons.setRotation(90);
                                                            train2.wagonsVec[0].wagons.setOrigin(0,24);
                                                        }
                                                        else if(PlayEvent.key.code == sf::Keyboard::Left)
                                                        {
                                                            dire = 4;
                                                            train2.wagonsVec[0].wagons.setRotation(270);
                                                            train2.wagonsVec[0].wagons.setOrigin(24,0);
                                                        }
                                                    }
                                    if(PlayEvent.type == Event::KeyPressed)
                                    {
                                        if(PlayEvent.key.code == Keyboard::Escape)
                                        {
                                            PlayWindow.close();
                                        }
                                    }
                                }
                                if (char1.char_picked == 1 && random == false)
                                            {
                                                random = true;
                                                srand(timee.asMilliseconds());
                                            }
                                if (goodBon.GoodBon_picked==1 && random == false)
                                    {
                                        random = true;
                                        srand(timee.asMilliseconds());
                                    }
                                if(goodBon.goodIsPicked(train2.wagonsVec[0].wagonPosX, train2.wagonsVec[0].wagonPosY))
                                {
                                    train2.deleteWagon();
                                }
                                 if(char1.isPicked(train2.wagonsVec[0].wagonPosX, train2.wagonsVec[0].wagonPosY))
                                        {
                                            score+=1;
                                            scoreText.setString(to_string(score));
                                            train2.addWagon();
                                            if(score>=max_score)
                                            {
                                                RenderWindow FinalWindow(VideoMode(800,600), "END");
                                                sf::Text endText;
                                                endText.setFont(font);
                                                endText.setString("CONGRATULATIONS!");
                                                endText.setCharacterSize(70);
                                                endText.setPosition(40,250);
                                                endText.setFillColor(sf::Color::Black);
                                                while(FinalWindow.isOpen())
                                                {
                                                    sf::Event ev;
                                                    while(FinalWindow.pollEvent(ev))
                                                    {
                                                        if(ev.type == Event::Closed)
                                                        {
                                                            FinalWindow.close();
                                                        }
                                                        if(ev.type == Event::KeyPressed)
                                                        {
                                                            if(ev.key.code==Keyboard::Escape)
                                                            {
                                                            FinalWindow.close();
                                                            }
                                                        }
                                                    }
                                                FinalWindow.clear();
                                                FinalWindow.draw(background2);
                                                FinalWindow.draw(endText);
                                                FinalWindow.display();
                                                PlayWindow.close();
                                                MenuWindow.close();
                                                }
                                            }
                                       }
                                train2.frontDirection(dire, train2Tex);
                                if(train2.inGame == false)
                                           {
                                               play = false;
                                               score = 0;
                                               scoreText.setString("0");
                                               clockk.restart();
                                           }
                            }
                            train2.wagonsVec[0].wagons.setPosition(train2.wagonsVec[0].wagonPosX*24, train2.wagonsVec[0].wagonPosY*24);
                                    //bottom border collision prevention
                                    if(train2.wagonsVec[0].wagons.getPosition().y+train2.wagonsVec[0].wagons.getGlobalBounds().height>PlayWindow.getSize().y-50){
                                        train2.wagonsVec[0].wagons.setPosition(train2.wagonsVec[0].wagons.getPosition().x, PlayWindow.getSize().y-train2.wagonsVec[0].wagons.getGlobalBounds().height);
                                    };
                            PlayWindow.clear();
                            PlayWindow.draw(background2);
                            PlayWindow.draw(char1.char1Spr);
                            PlayWindow.draw(goodBon.goodBonSpr);
                            PlayWindow.draw(train2.wagonsVec[0].wagons);
                            for(int i = 1; i < train2.numOfWagons; i++)
                               {
                                   PlayWindow.draw(train2.wagonsVec[i].wagons);
                               }
                            PlayWindow.draw(text);
                            Play.drawP(PlayWindow);
                            PlayWindow.draw(scoreText);
                            PlayWindow.draw(textTimer);
                            PlayWindow.display();
                            OptionWindow.close();
                        }
                }
                    if(m==2)
                    {
                        MenuWindow.close();
                        break;
                    }
                }
            }
        }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                MenuWindow.close();
            }
        MenuWindow.clear();
        MenuWindow.draw(background);
        MainMenu.draw(MenuWindow);
        MenuWindow.display();
    }
    return EXIT_SUCCESS;
}

