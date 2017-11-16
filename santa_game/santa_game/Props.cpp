#include "stdafx.h"
#include "Props.h"
#include "Santa.h"
#include "Elf.h"
#include <iostream>
#include <list>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

Props::Props(float x)
{
	//Constructor
	// set_y =  !!Find hand position of santa!!  ;


	//If statement that chooses which item shall be dropped. Coal or gift.
	set_type(rand() % 3);
	set_image();
	//The setup for the position of X(The picture)
	set_x(x);

	set_gravity(0.5);

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

Sprite* Props::get_image() {
	return prop_sprite;
}

int Props::get_type() {
	return type;
}
void Props::set_type(int type) {
	this->type = type;
}
void Props::set_image()
{
	if (this->type == 0) {
		this->texture = new Texture();
		if (texture->loadFromFile("coal_sprite.png") != true) {
			cout << "can't load file 'coal_sprite.png'" << endl;
		}
		this->prop_sprite = new Sprite();

		this->prop_sprite->setTexture(*texture);
	}
	else {
		this->texture = new Texture();
		if (texture->loadFromFile("present_sprite.png") != true) {
			cout << "can't load file 'present_sprite.png'" << endl;
		}
		this->prop_sprite = new Sprite();

		this->prop_sprite->setTexture(*texture);
	}
}