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

	this->drop_list = new vector<Props*>(); // creating an random prop class object
	this->texture = new Texture(); // giving it a texture
	if (texture->loadFromFile("santa_sprite.png") != true) { // if the file can be loaded display this image
		cout << "can't load file 'santa_sprite.png'" << endl; // if it cant it shows the message " cant load file"
	}
	cout << texture << endl; 
	this->santa_sprite = new Sprite(); 

	this->santa_sprite->setTexture(*texture); 
}

Santa::~Santa()
{
}
// actions 
void Santa::createDrop(float x) {

}

void Santa::action() {
	this->props = new Props(this->get_x()); // creating an random prop class object with x position
	drop_list->push_back(props);
}


//// Get's and setters
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

void Santa::set_drop_list(vector<Props*>* droplist)
{
	this->drop_list = droplist;
}
