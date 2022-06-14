#include "Wagons.hpp"
#include <iostream>
trainBody::trainBody()
{
 numOfWagons = 1;
 inGame = true;
}
void trainBody::addWagon()
{
 numOfWagons++;
 Wagons neww(-1, -1);
 wagonsVec.push_back(neww);
}
void trainBody::deleteWagon()
{
 numOfWagons--;
 Wagons neww(-1, -1);
 wagonsVec.push_back(neww);
}
int trainBody::frontDirection(int direction, sf::Texture &train2Tex)
{
 int sign = direction % 2;
 for(int i = 1; i < numOfWagons; i++)
 {
 wagonsVec[numOfWagons-i].wagons.setTexture(train2Tex);
 wagonsVec[numOfWagons-i].wagons.setOrigin(0,0);
 wagonsVec[numOfWagons-i].wagons.setPosition(wagonsVec[numOfWagons-i-1].wagonPosX * 24, wagonsVec[numOfWagons-i-1].wagonPosY * 24);
 wagonsVec[numOfWagons-i].wagons.setRotation(0);
 wagonsVec[numOfWagons-i] = wagonsVec[numOfWagons-i-1];
 }
 if(direction > 2)
 wagonsVec[0].wagonPosX = wagonsVec[0].wagonPosX + sign * 2 -1;
 if(direction < 3)
 wagonsVec[0].wagonPosY = wagonsVec[0].wagonPosY - sign * 2 +1;

 if(wagonsVec[0].wagonPosX < 0 || wagonsVec[0].wagonPosX > 29 ||
 wagonsVec[0].wagonPosY < 0 || wagonsVec[0].wagonPosY > 24 || gamemap
 [wagonsVec[0].wagonPosX][wagonsVec[0].wagonPosY] == 1)
 {
 inGame = false;
 return 0;
 }
 if (gamemap [wagonsVec[0].wagonPosX][wagonsVec[0].wagonPosY] < 2) //if snake has not moved onto a food space
     gamemap [wagonsVec[0].wagonPosX][wagonsVec[0].wagonPosY] = 1; //snake is now on this space. This code is necessary in order to prevent food spaces from being overwritten before being read
 if (gamemap [wagonsVec.back().wagonPosX][wagonsVec.back().wagonPosY] == 1) //last segment of snake has passed
     gamemap [wagonsVec.back().wagonPosX][wagonsVec.back().wagonPosY] = 0; //there is no longer a snake in this position
 return 0;
 }
Wagons::Wagons()
{
 wagonPosX = 15;
 wagonPosY = 10;
 wagons.setPosition(wagonPosX*24, wagonPosY*24);
}
Wagons::Wagons(float x, float y)
{
 wagonPosX = x;
 wagonPosY = y;
}
