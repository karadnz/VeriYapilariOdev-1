
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
	friend ostream& operator<<(ostream& OUT, SatirListesi& LIST);
	void	printLine(int count);
	void	clear();
	~SatirListesi();

};


#endif