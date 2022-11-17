#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "utils.cpp"
#include "navUtils.cpp"

#include <fstream>
#include <sstream>

using namespace std;

int main()
{

	YoneticiListesi *yntLst = new YoneticiListesi;
	yoneticiInit(yntLst);

	bool flag = true;
	bool delFlag = false;
	int delIndex = 0;

	int end = 8;	  // last index+1 to display
	int selected = 0; // index in page
	
	while (flag)
	{
		system("clear");

		yntLst->sort();
		printYoneticiNodes(yntLst, end);
		printSelectedSatirListesi(yntLst, selected, end, delFlag, delIndex);

		char islem;
		cout << "islem: ";
		cin >> islem;
		cout << endl;

		switch (islem)
		{
		case 'z':
		{
			navOneBack(yntLst, end, selected);
			delIndex = 0;
			delFlag = 0;
			break;
		}

		case 'c':
		{
			navOneForward(yntLst, end, selected);
			delIndex = 0;
			delFlag = 0;
			break;
		}

		case 'a':
		{
			navPageBack(yntLst, end, selected);
			delIndex = 0;
			delFlag = 0;
			break;
		}

		case 'd':
		{
			navPageForward(yntLst, end, selected);
			delIndex = 0;
			delFlag = 0;
			break;
		}

		case 'p':
		{
			navDelYoneticiNode(yntLst, end, selected);
			delIndex = 0;
			delFlag = 0;
			break;
		}

		case 'k':
		{
			navRandomDel(yntLst, end, selected, delFlag, delIndex);
			break;
		}

		case 'q':
		{
			flag = false;
			break;
		}

		default:
			break;
		}
	}
	return (0);
}