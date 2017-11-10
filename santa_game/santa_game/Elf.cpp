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
	bool catch_prop;
	for (int i = 0; i > santa->get_drop_list()->size();i++){
		if ((santa->get_drop_list()->operator[](i)->get_image()->getPosition().x + santa->get_drop_list()->operator[](i)->get_image()->getGlobalBounds().width) >= (this->get_img()->getPosition().x) &&
			(santa->get_drop_list()->operator[](i)->get_image()->getPosition().x) <= (this->get_img()->getPosition().x + (this->get_img()->getGlobalBounds().width)) &&
			(santa->get_drop_list()->operator[](i)->get_image()->getPosition().y + santa->get_drop_list()->operator[](i)->get_image()->getGlobalBounds().height) >= (this->get_img()->getPosition().y) &&
			(santa->get_drop_list()->operator[](i)->get_image()->getPosition().y) <= (this->get_img()->getPosition().y + (this->get_img()->getGlobalBounds().height))) {
			catch_prop = true;
			cout << "CATCH!" << endl;
		}
		else {
			catch_prop = false;
			cout << "CATCH FAILED" << endl;
		}
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