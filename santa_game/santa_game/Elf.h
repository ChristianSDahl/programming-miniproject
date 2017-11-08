#pragma once
#include "Player.h"
#include "stdafx.h"
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Elf :
	public Player
{
	int lives;
	vector<vector<Point>> hitbox;
	float y;
	Texture* texture;
	Sprite* elf_sprite;
public:
	Elf(float x);
	~Elf();

	void action();
	float get_y();
	void set_y(float y);
	Sprite* get_img();
};
