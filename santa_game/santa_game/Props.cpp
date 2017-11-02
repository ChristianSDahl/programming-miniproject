#include "stdafx.h"
#include "Props.h"


Props::Props(float x)
{
	//Constructor
	// set_y =  !!Find hand position of santa!!  ;


	//If statement that chooses which item shall be dropped. Coal or gift.
	set_type(rand() % 3);
	if (type == 0) {
		//set_img  !!Insert image of coal!!  ;
	}
	else {
		//set_img !!Insert image of gift!!  ;
	}

	//The setup for the position of X(The picture)
	set_x(x);

	set_gravity(rand() % 20);

	//Create termination factor
}


Props::~Props()
{
}

void Props::fall() {
	set_y(get_y() + get_gravity());
}

// Get's and setters
float Props::get_x() {
	return x;
}
void Props::set_x(float x) {
	this->x = x;
}


float Props::get_y() {
	return y;
}
void Props::set_y(float y) {
	this->y = y;
}

float Props::get_gravity() {
	return gravity;
}
void Props::set_gravity(float gravity) {
	this->gravity = gravity;
}

Mat Props::get_image() {
	return img;
}
void Props::set_image(Mat image) {
	this->img = image;
}

int Props::get_type() {
	return type;
}
void Props::set_type(int type) {
	this->type = type;
}