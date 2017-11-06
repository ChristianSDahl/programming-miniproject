#include "stdafx.h"
#include "Elf.h"

Elf::Elf(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(820);
	//Sets x-value for the santa object
	set_x(x);
}


Elf::~Elf()
{
}

void Elf::action() {

}

float Elf::get_y() {
	return y;
}

void Elf::set_y(float y) {
	this->y = y;
}