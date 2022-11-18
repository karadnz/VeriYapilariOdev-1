/**
* @file main.cpp
* @description main function.
* @course 2-A
* @assignment 1.
* @date 
* @author Mustafa Karadeniz mustafa.karadeniz1@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "utils.hpp"
#include "navUtils.hpp"

using namespace std;

//bas son oklarini ekle

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

		

		if(!yntLst->isEmpty())
		{
			yntLst->sort();
			printYoneticiNodes(yntLst, end);
			printSelectedSatirListesi(yntLst, selected, end, delFlag, delIndex);
		}
		else
		{
			cout << "empty list";
			break;
		}
		

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