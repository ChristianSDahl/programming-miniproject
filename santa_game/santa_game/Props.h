#pragma once
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Props
{
	float x;
	float y;
	float gravity;
	Mat img;
	int type;

public:
	Props(float x);
	~Props();

	float fall();

	// Get's and Setters
	float get_x();
	void set_x(float x);
	float get_y();
	void set_y(float y);
	float get_gravity();
	void set_gravity(float gravity);
	Mat get_image();
	void set_image(Mat image);
	int get_type();
	void set_type(int type);

};

