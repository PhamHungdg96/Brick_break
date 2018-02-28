#include"Ball.h"
#define WIN_WIDTH 640
#define WIN_HEIGHT 680
Ball::Ball() {

}
Ball::Ball(Entiny* entiny, Live *live) {
	this->live = live;
	this->entiny = entiny;
	this->vector.x = 0.0f;
	this->vector.y = 0.0f;
	this->buffer = new sf::SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new sf::Sound(*this->buffer);
}
void Ball::Init(float x, float y) {
	this->vector.x = x;
	this->vector.y = y;
}
void Ball::SetMove(float x, float y) {
	this->vector.x = x;
	this->vector.y = y;
}
void Ball::Update() {
	float x = 1.0, y = 1.0;
	if (this->check_collision(this->entiny) && this->getPosition().y + this->getGlobalBounds().height > this->entiny->getPosition().y) {
		if (this->getPosition().x + this->getGlobalBounds().width / 2 >= this->entiny->getPosition().x - this->entiny->getGlobalBounds().width * 2 / 6
			&& this->getPosition().x + this->getGlobalBounds().width / 2 <= this->entiny->getPosition().x + this->entiny->getGlobalBounds().width * 2 / 6) {
			y *= -1.0;
			if (this->vector.x < 0)this->vector.x = -2;
			else this->vector.x = 2;
		}
		else {
			y *= (float)-1.0;
			if (this->vector.x > 0 && this->getPosition().x + this->getGlobalBounds().width / 2 < this->entiny->getPosition().x - this->entiny->getGlobalBounds().width * 2 / 6)
				x *= -1.5;
			else if (this->vector.x <  0 && this->getPosition().x + this->getGlobalBounds().width / 2 > this->entiny->getPosition().x + this->entiny->getGlobalBounds().width * 2 / 6)
				x *= -1.5;
		}
		//this->sound->play();
	}
	if (this->getPosition().x < 0 || this->getPosition().x + this->getGlobalBounds().width>WIN_WIDTH) {
		x *= -1.0;
	}
	if (this->getPosition().y < 0) {
		y *= -1.0;
	}
	if (this->getPosition().y > WIN_HEIGHT) {
		this->live->increase_point();
		this->live->SetGone(false);
	}
	this->vector.x *= x;
	this->vector.y *= y;
	Entiny::Update();
}
void Ball::Play_Sound() {
	this->sound->play();
}