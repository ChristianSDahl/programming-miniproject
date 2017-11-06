#pragma once
#include "Player.cpp"
#include "Props.cpp"
class Santa : public Player
{
	float y;
	vector<Props> drop_list;
	//Props drop_array[];
public:
	Santa(float x);
	~Santa();

	void createDrop(float x);
	void action();

	float get_y();
	void set_y(float y);
};

