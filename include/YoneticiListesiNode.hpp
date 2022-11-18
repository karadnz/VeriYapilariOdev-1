/**
* @file main.cpp
* @description Header file.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#ifndef YONETICILISTESINODE_HPP
#define YONETICILISTESINODE_HPP

#include "SatirListesi.hpp"

class YoneticiListesiNode
{
	public:

	SatirListesi *data;
	double average;
	YoneticiListesiNode *next;
	YoneticiListesiNode *prev;

	YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next =NULL, YoneticiListesiNode *prev = NULL);

	
	double getAverage();

};


#endif