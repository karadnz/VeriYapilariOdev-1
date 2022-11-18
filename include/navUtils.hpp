#ifndef NAVUTILS_HPP
#define NAVUTILS_HPP

#include "YoneticiListesi.hpp"
using namespace std;

void navOneBack(YoneticiListesi *yntLst, int &end, int &selected);
void navOneForward(YoneticiListesi *yntLst, int &end, int &selected);
void navPageBack(YoneticiListesi *yntLst, int &end, int &selected);
void navPageForward(YoneticiListesi *yntLst, int &end, int &selected);
void navDelYoneticiNode(YoneticiListesi *yntLst, int &end, int &selected);
void navRandomDel(YoneticiListesi *yntLst, int &end, int &selected, bool& delFlag, int& delIndex);


#endif