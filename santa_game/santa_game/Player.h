#pragma once
#include <opencv2/highgui/highgui.hpp> // import no include errors
#include <opencv2/imgproc/imgproc.hpp> // import no include errors 
#include <opencv2/core/core.hpp>       // import no include errors

using namespace cv;
using namespace std;

class Player
{
	float cd;
	float x, y;
	Mat img;
	int score;
	int speed;
public:
	Player();
	~Player();
};

