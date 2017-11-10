#include "stdafx.h"
#include "Elf.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Santa.h"

using namespace std;
using namespace sf;

Elf::Elf(float x)
	: Player(x)
{
	//Sets y-value for the santa object
	set_y(690);
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

void Elf::action(Santa* santa) {
	bool catch_prop();
	for (int i = 0; i )
		if ((prop_sprite.x + prop_sprite.width) >= (this->get_img()->getPosition().x) &&
			(prop_sprite.x) <= (elf_sprite.x + elf_sprite.width) &&
			(prop_sprite.y + prop_sprite.height) >= (elf_sprite.y) &&
			(prop_sprite.y) <= (elf_sprite.y + elf_sprite.height))
		return true;
		cout << "CATCH!" << endl;

		else return false;
		cout << "CATCH FAILED" << endl;
	}
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