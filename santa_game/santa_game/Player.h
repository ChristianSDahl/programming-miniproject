#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

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

