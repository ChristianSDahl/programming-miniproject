#pragma once
#include "opencv2/opencv.hpp"
#include "Santa.h"
#include "Elf.h"

using namespace std;
using namespace cv;

class Field
{
	Mat image;
	int limitx;
	int limity;

public:
	Field();
	~Field();

	void spawn();

};

