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

	float move(float x, float y);
	void action();

	float get_x();
	void set_x(float x);
	float get_y();
	void set_y(float y);
	float get_score();
	void set_score(float score);
	float get_speed();
	void set_speed(float speed);
	float get_cooldown();
	void set_cooldown(float cd);
};

