// santa_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	std::vector<int> mylist;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		mylist.push_back(myint);
		std::cin >> myint;
		mylist.push_back(myint);
		break;
	} while (myint);

	std::cout << "mylist stores " << mylist.size() << " numbers.\n" << endl;
	for (int i = 0; i < mylist.size();i++) {
		std::cout << mylist[i] << endl;
	}
	//getchar;
	return 0;
}

