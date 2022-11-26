/**
* @file navUtils.cpp
* @description cpp file for navUtils.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "navUtils.hpp"


void navOneBack(YoneticiListesi *yntLst, int &end, int &selected)
{
    if (selected == 0)
    {
        if (end != 8)
        {
            end -= 8;
            selected = 7;
        }
    }
    else
    {
        selected--;
    }
}

void navOneForward(YoneticiListesi *yntLst, int &end, int &selected)
{
    if (selected == 7 && !(end >= yntLst->Size()))
    {
        selected = 0;
        if (end < yntLst->Size())
        {
            end += 8;
        }
    }
    else
    {
        if (end <= yntLst->Size() && selected != 7)
            selected++;
        else if (selected + 1 < (yntLst->Size() % 8)) // son 8likte 8den az varsa diye
            selected++;
    }
}

void navPageBack(YoneticiListesi *yntLst, int &end, int &selected)
{
    selected = 0;
    if (end != 8)
    {
        end -= 8;
    }
}

void navPageForward(YoneticiListesi *yntLst, int &end, int &selected)
{
    if (end < yntLst->Size())
    {
        selected = 0;
        end += 8;
    }
}

void navDelYoneticiNode(YoneticiListesi *yntLst, int &end, int &selected)
{
    int selectedIndex = (end - (7 - selected)) - 1;
    yntLst->removeAt(selectedIndex);
    if (end >= yntLst->Size() && selectedIndex == yntLst->Size())
    {
        if (selected == 0)
        {
            navOneBack(yntLst, end, selected);
        }
        else
        {
            selected--;
        }
        
    }
}

void navRandomDel(YoneticiListesi *yntLst, int &end, int &selected, bool& delFlag, int& delIndex)
{
    int selectedIndex = (end - (7 - selected)) - 1;

    if (!delFlag)
    {
        delFlag = true;
        srand(time(NULL));
        delIndex = (rand() % yntLst->FindPrevByPosition(selectedIndex)->next->data->Size());
        
    }

    else
    {
        
        yntLst->FindPrevByPosition(selectedIndex)->next->data->removeAt(delIndex);
        yntLst->FindPrevByPosition(selectedIndex)->next->average = yntLst->FindPrevByPosition(selectedIndex)->next->getAverage();
        
    
        if (yntLst->FindPrevByPosition(selectedIndex)->next->data->isEmpty())
        {
            yntLst->removeAt(selectedIndex);
            navOneBack(yntLst, end, selected);
        }
        else
        {
            yntLst->sortNode(selectedIndex);
        }

        delFlag = 0;
        selectedIndex = 0;
    }
}