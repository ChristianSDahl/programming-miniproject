#include "stdafx.h"
#include "Santa.h"

Santa::Santa(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(120);
}

Santa::~Santa()
{
}

void Santa::createDrop(float x) {

}

void Santa::action() {

}

float Santa::get_y() {
	return y;
}
void Santa::set_y(float y) {
	this->y = y;
}