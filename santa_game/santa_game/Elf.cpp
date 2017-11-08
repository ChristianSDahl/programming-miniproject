#include "stdafx.h"
#include "Elf.h"
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Elf::Elf(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(820);
	//Sets x-value for the santa object
	set_x(x);

	this->texture = new Texture();
	if (texture->loadFromFile("elf_sprite.png") != true) {
		cout << "can't load file 'santa_sprite.png'" << endl;
	}
	this->elf_sprite = new Sprite();
	this->elf_sprite->setTexture(*texture);
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

Sprite* Elf::get_img() {
	return elf_sprite;
}