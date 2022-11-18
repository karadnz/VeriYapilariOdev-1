/**
* @file main.cpp
* @description Header file.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP


#include "SatirListesiNode.hpp"
//#include "NoSuchElement.hpp"
#include <iomanip>

class SatirListesi
{
	private:

	SatirListesiNode *head;
	int size;


	friend class YoneticiListesi; ////

	SatirListesiNode	*FindPrevByPosition(int pos);

	public:

	SatirListesi();
	int		Size()const;
	bool	isEmpty()const;
	void	add(const int& num);
	void	insert(int index, const int& num);
	const int& first();
	const int& last();
	void	remove(const int& num);
	void	removeAt(int index);
	bool	find(const int& item)const;
	void	reverse();
	int		indexOf(const int& item);
	const int& elementAt(int index);

	SatirListesiNode* getHead();
	friend ostream& operator<<(ostream& OUT, SatirListesi& LIST);
	//friend void printSelectedSatirListesi(YoneticiListesi *LIST, int selected, int end);
	////
	void	printLine(int count);
	void	clear();
	~SatirListesi();

};


#endif