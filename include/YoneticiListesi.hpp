#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include "SatirListesi.hpp"
#include "YoneticiListesiNode.hpp"
#include <iostream>

class YoneticiListesi
{
	private:

	YoneticiListesiNode *head;
	int size;

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
	void printLine(int count);
	void tempDisplay(int index);
	void clear();
	~YoneticiListesi();


};

#endif