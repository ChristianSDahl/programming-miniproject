#include "Player.h"
#include "stdafx.h"
class Elf :
	public Player
{
	int lives;
	vector<vector<Point>> hitbox;
	float y;
public:
	Elf(float x);
	~Elf();

	void action();
	float get_y();
	void set_y(float y);
};
