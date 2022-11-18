/**
* @file main.cpp
* @description cpp file for YoneticiListesiNode.hpp.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "YoneticiListesiNode.hpp"

YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next, YoneticiListesiNode *prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;

	this->average = getAverage();
}

double YoneticiListesiNode::getAverage()
{
	if (this->data->isEmpty())
		return (0);

	double sum = 0;
	int count = this->data->Size();
	for (int i = 0; i < count; i++)
	{
		sum += this->data->elementAt(i);
	}

	return (sum / count);
}
