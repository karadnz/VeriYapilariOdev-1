#ifndef UTILS_HPP
#define UTILS_HPP

#include "YoneticiListesi.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void printLine(int count);
void printYoneticiNodes(YoneticiListesi *LIST, int end);
void printSelectedSatirListesi(YoneticiListesi *LIST, int selected, int end, bool delFlag, int delIndex);
void printSelectedLine(int selected);
void printSpace(int selected);
void	yoneticiInit(YoneticiListesi *yntLst);

#endif