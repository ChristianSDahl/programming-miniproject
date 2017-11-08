#pragma once
#include <opencv2/highgui/highgui.hpp> // import no include errors
#include <opencv2/imgproc/imgproc.hpp> // import no include errors 
#include <opencv2/core/core.hpp>       // import no include errors

using namespace cv;
using namespace std;

class Player
{
	int type;
	Mat img;
	float x, y;
	int score;
	int speed;
	float cd;
public:
	Player(float x);
	~Player();

	void move();
	void action();

	int get_type();
	void set_type(int type);
	Mat get_img();
	void set_img(Mat img);
	float get_x();
	void set_x(float x);
	float get_score();
	void set_score(float score);
	float get_speed();
	void set_speed(float speed);
	float get_cooldown();
	void set_cooldown(float cd);
	void move_x(float x);
};

