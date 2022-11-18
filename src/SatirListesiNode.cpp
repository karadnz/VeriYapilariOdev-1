/**
* @file SatirListesiNode.cpp
* @description cpp file for SatirListesiNode.hpp.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "SatirListesiNode.hpp"


SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
