#include "Play.hpp"

Play::Play(float widthP, float heightP)
{
    textP[0].setFont(font);
    textP[0].setFillColor(sf::Color::Black);
    textP[0].setString("SCORE: ");
    textP[0].setPosition(50, 550);

    textP[1].setFont(font);
    textP[1].setFillColor(sf::Color::Black);
    textP[1].setString("LEVEL: ");
    textP[1].setPosition(530, 550);
}

Play::~Play()
{
    
};

void Play::drawP(sf::RenderWindow &window)
{
    for(int t=0; t < 2; ++t)
    {
        window.draw(textP[t]);
    }
}
