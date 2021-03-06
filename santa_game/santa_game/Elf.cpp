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
	if (texture->loadFromFile("elf_sprite.png") != true) { // if the file can be loaded display this image
		cout << "can't load file 'santa_sprite.png'" << endl; // if it cant it shows the message " cant load file"
	}
	this->elf_sprite = new Sprite();
	this->elf_sprite->setTexture(*texture); // creating an elf class object
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
			cout << "CATCH!" << endl; // is statement checking if the elf caught the prop based on the player and prop position, if yes it displays text "catch!"
		}
		else {
			catch_prop = false;
			cout << "CATCH FAILED" << endl; // it the player failed to catch the prop, it displays text "catch failed"
		}
	}
}
// Get's and setters
float Elf::get_y() {
	return y;
}

void Elf::set_y(float y) {
	this->y = y;
}

Sprite* Elf::get_img() {
	return elf_sprite;
}