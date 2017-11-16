#pragma once

//using namespace std;

class Player
{
	int type;
	float x, y;
	int score;
	int speed;
	float cd;
public:
	Player(float x);
	~Player();

	void move();
	void action();

	int get_type();
	void set_type(int type);
	float get_x();
	void set_x(float x);
	float get_score();
	void set_score(float score);
	float get_speed();
	void set_speed(float speed);
	float get_cooldown();
	void set_cooldown(float cd);
	void move_x(float x);
};

