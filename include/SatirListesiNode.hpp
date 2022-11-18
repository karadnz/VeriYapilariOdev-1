/**
* @file main.cpp
* @description Header File.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/

#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTESINODE_HPP

#include <iostream>
using namespace std;

class SatirListesiNode
{
	public:

	int data;
	SatirListesiNode *next;
	SatirListesiNode *prev;

	SatirListesiNode(const int data, SatirListesiNode *next = NULL, SatirListesiNode *prev = NULL);

};


#endif