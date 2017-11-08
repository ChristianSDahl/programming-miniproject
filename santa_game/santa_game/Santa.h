#pragma once
#include "Player.h"
#include "Props.h"
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Santa : public Player
{
	float y;
	Props* props;
	vector<Props*>* drop_list;
	Texture* texture;
	Sprite* santa_sprite;
public:
	Santa(float x);
	~Santa();

	void createDrop(float x);
	void action();

	float get_y();
	void set_y(float y);
	Sprite* get_img();
};

