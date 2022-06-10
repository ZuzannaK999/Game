#include "Sceneries.hpp"
Sceneries::Sceneries(float width, float height) : Game()
{
 textS[0].setFont(font);
 textS[0].setFillColor(sf::Color::Red);
 textS[0].setString("Desert");
 textS[0].setPosition(sf::Vector2f(width/2, height/(max_num_of_choices_S + 1)*1));
 textS[1].setFont(font);
 textS[1].setFillColor(sf::Color::Black);
 textS[1].setString("Sea");
 textS[1].setPosition(sf::Vector2f(width/2, height/(max_num_of_choices_S + 0.9)*2));
 SelectedScenery=0;
}
Sceneries::~Sceneries()
{
};
void Sceneries::drawS(sf::RenderWindow &window)
{
 for(int s=0; s < max_num_of_choices_S; s++)
 {
 window.draw(textS[s]);
 }
}
void Sceneries::MoveUpS()
{
 if(SelectedScenery - 1 >= 0)
 {
 textS[SelectedScenery].setFillColor(sf::Color::Black);
 SelectedScenery--;
 textS[SelectedScenery].setFillColor(sf::Color::Red);
 }
}
void Sceneries::MoveDownS()
{
 if(SelectedScenery + 1 < max_num_of_choices_S)
 {
 textS[SelectedScenery].setFillColor(sf::Color::Black);
 SelectedScenery++;
 textS[SelectedScenery].setFillColor(sf::Color::Red);
 }
}
