#include "Passengers.hpp"
#include <cstdlib>
#include <iostream>
Passengers::Passengers()
{
 charPosX = 22;
 charPosY = 20;
 gamemap[charPosX][charPosY] = 5;
 char1Spr.setPosition(charPosX*24, charPosY*24);
};
bool Passengers::isPicked(int x, int y)
{
 if (gamemap [x][y] >= 2 && gamemap [x][y] < 10)
 {
 gamemap [x][y] = 1;
 char_picked++;
 while(gamemap[charPosX][charPosY] == 1 || gamemap[charPosX][charPosY] == 10)
 {
 charPosX = rand() % 30;
 charPosY = rand() % 20;
 }
 gamemap [charPosX][charPosY] += 5;
 char1Spr.setPosition(charPosX*24, charPosY*24);
 return true;
 }
 return false;
};
void Passengers::spawn()
{
 charPosX = rand() % 30;
 charPosY = rand() % 20;
 gamemap [charPosX][charPosY] += 5;
 char1Spr.setPosition(charPosX*24, charPosY*24);
}
