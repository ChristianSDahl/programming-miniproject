#pragma once
#include "Player.h"
class Santa : public Player
{
	float y;
public:
	Santa(float x);
	~Santa();

	void createDrop(float x);
	void action();

	float get_y();
	void set_y(float y);
};

