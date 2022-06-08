#include "GoodBonus.hpp"
GoodBonus::GoodBonus()
{
 goodBonPosX = 40;
 goodBonPosY = 30;
 gamemap[goodBonPosX][goodBonPosX] = 10;
 goodBonSpr.setPosition(goodBonPosX*24, goodBonPosY*24);
};
bool GoodBonus::goodIsPicked(int x, int y)
{
 if(gamemap[x][y] == 10)
 return true;
 return false;
};
void GoodBonus::spawn()
{
 goodBonPosX = rand() % 30;
 goodBonPosY = rand() % 20;
 gamemap [goodBonPosX][goodBonPosY] += 5;
 goodBonSpr.setPosition(goodBonPosX*24, goodBonPosY*24);
 while(gamemap[goodBonPosX][goodBonPosY] != 0)
 {
 goodBonPosX = rand() % 30;
 goodBonPosY = rand() % 20;
 }
 goodBonSpr.setPosition(goodBonPosX * 24, goodBonPosY * 24);
 gamemap[goodBonPosX][goodBonPosY] = 10;

}
