/**
* @file SatirListediNode.hpp
* @description header
* @course 2A
* @assignment 1
* @date Kodu oluşturduğunuz Tarih
* @author Mustafa Karadeniz
*/

#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTEDINODE_HPP

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