#include "stdafx.h"
#include "Santa.h"

#include <iostream>
#include <list>

using namespace std;

Santa::Santa(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(120);

	vector<Props>* drop_list;
}

Santa::~Santa()
{
}

void Santa::createDrop(float x) {

}

void Santa::action() {
	Props temp(this->get_x());
	drop_list.push_back(temp);
}

float Santa::get_y() {
	return y;
}
void Santa::set_y(float y) {
	this->y = y;
}