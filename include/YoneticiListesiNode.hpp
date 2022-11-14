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