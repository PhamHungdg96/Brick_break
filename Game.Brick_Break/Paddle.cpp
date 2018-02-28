#include"Paddle.h"
#define WIN_WIDTH 640
#define WIN_HEIGHT 680

Paddle::Paddle() {
	//this->Load("paddle2.PNG");
	//this->setOrigin(this->getGlobalBounds().width / 2, 0);
	this->flip = false;
	this->wrap = false;
}
void Paddle::Update() {
	if (this->flip == false)
		this->vector.x = (float)(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) * this->speed;
	//this->vector.x=(float)(s);
	else
		this->vector.x = (float)(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) * this->speed;

	if (this->wrap == false) {
		if (this->getPosition().x < 0 && this->vector.x < 0) {
			this->vector.x *= -1;
		}

		if ((this->getPosition().x) > WIN_WIDTH && this->vector.x > 0) {
			this->vector.x *= -1;
		}
	}
	else {
		if (this->getPosition().x < 0 && this->vector.x < 0) {
			this->setPosition(WIN_WIDTH, this->getPosition().y);
		}

		if ((this->getPosition().x) > WIN_WIDTH && this->vector.x > 0) {
			this->setPosition(0, this->getPosition().y);
		}
	}
	Entiny::Update();
}
void Paddle::setFlip(bool flip) {
	this->flip = flip;
}
void Paddle::setWrap(bool wrap) {
	this->wrap = wrap;
}