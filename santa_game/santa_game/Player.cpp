#include "stdafx.h"
#include "Player.h"

Player::Player(float middle)
{

	set_x(middle);
	set_score(0);
	set_speed(5);
	set_cooldown(100);
}

Player::~Player()
{
}

void Player::move() {
	set_x(get_x()+get_speed());
}
void Player::action() {

}

//Get's and Setter's
int Player::get_type() {
	return type;
}
void Player::set_type(int type) {
	this->type = type;
}
Mat Player::get_img() {
	return img;
}
void Player::set_img(Mat img) {
	this->img = img;
}
float Player::get_x() {
	return x;
}
void Player::set_x(float x) {
	this->x = x;
}
float Player::get_score() {
	return score;
}
void Player::set_score(float score) {
	this->score = score;
}
float Player::get_speed() {
	return speed;
}
void Player::set_speed(float speed) {
	this->speed = speed;
}
float Player::get_cooldown() {
	return cd;
}
void Player::set_cooldown(float cd) {
	this->cd = cd;
}