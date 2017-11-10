#include "stdafx.h"
#include "Santa.h"

#include <iostream>
#include <list>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;


Santa::Santa(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(120);
	//Sets x-value for the santa object
	set_x(x);

	this->drop_list = new vector<Props*>();
	this->texture = new Texture();
	if (texture->loadFromFile("santa_sprite.png") != true) {
		cout << "can't load file 'santa_sprite.png'" << endl;
	}
	cout << texture << endl;
	this->santa_sprite = new Sprite();

	this->santa_sprite->setTexture(*texture);
}

Santa::~Santa()
{
}

void Santa::createDrop(float x) {

}

void Santa::action() {
	this->props = new Props(this->get_x());
	drop_list->push_back(props);
	for (int i = 0; i < drop_list->size(); i++) {
		cout << "list" << endl;
		cout << drop_list->operator[](i)->get_x() << endl;
	}
}

float Santa::get_y() {
	return y;
}
void Santa::set_y(float y) {
	this->y = y;
}

Sprite* Santa::get_img() {
	return santa_sprite;
}

vector<Props*>* Santa::get_drop_list() {
	return drop_list;
}