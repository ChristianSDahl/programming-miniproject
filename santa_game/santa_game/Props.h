#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Props
{
	float x;
	float y;
	float gravity;
	int type;

	Texture* texture;
	Sprite* prop_sprite;

public:
	Props(float x);
	~Props();

	void fall();

	// Get's and Setters
	float get_x();
	void set_x(float x);
	float get_y();
	void set_y(float y);
	float get_gravity();
	void set_gravity(float gravity);
	Sprite* get_image();
	int get_type();
	void set_type(int type);
	void set_image();
};

