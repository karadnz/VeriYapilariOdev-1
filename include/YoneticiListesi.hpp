/**
* @file YoneticiListesi.hpp
* @description Header file.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include "SatirListesi.hpp"
#include "YoneticiListesiNode.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class YoneticiListesi
{
	private:

	YoneticiListesiNode *head;
	int size;

	friend class SatirListesi; ////

	YoneticiListesiNode *FindPrevByPosition(int pos);

	public:

	YoneticiListesi();
	int Size() const;
	bool isEmpty() const;
	void add(SatirListesi *&item);
	void insert(int index, SatirListesi *&item);
	SatirListesi *&first();
	SatirListesi *&last();
	void remove(SatirListesi *&item);
	void removeAt(int index);
	bool find(SatirListesi *&item) const;
	void reverse();
	int indexOf(SatirListesi *&item);
	SatirListesi *&elementAt(int index);
	
	friend ostream &operator<<(ostream &OUT, YoneticiListesi &LIST);
	friend void printYoneticiNodes(YoneticiListesi *LIST, int start);
	friend void printSelectedSatirListesi(YoneticiListesi *LIST, int selected, int end, bool delFlag, int delIndex);
	friend void navRandomDel(YoneticiListesi *yntLst, int &end, int &selected, bool& delFlag, int& delIndex);


	//YoneticiListesiNode *&YoneticiListesiNodeAt(int index);

	void printLine(int count);
	void tempDisplay(int index);
	void clear();
	
	void sort();
	~YoneticiListesi();


};

#endif