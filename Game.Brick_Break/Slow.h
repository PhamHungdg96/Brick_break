#pragma once
// bong di cham lai
#include"Fall.h"
#include"Live.h"
#include"Entiny.h"
#include<iostream>
// them mot lan choi neu chet
class Slow :public Fall {
public:
	Slow(Entiny *entiny_paddle, Entiny *entiny_ball, float X, float Y) {
		Fall::Init("Graphic/slow.png");
		Fall::SetPosition_origin(X, Y);
		this->entiny_paddle = entiny_paddle;
		this->entiny_ball = entiny_ball;
	}
	void Update() {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			this->move(0, 2.5);
		}
	}
	bool Reset() {
		if ((float)this->clock.getElapsedTime().asSeconds() - (float)this->_time.asSeconds() >= 10&&(this->entiny_ball->vector.x<2.5 && this->entiny_ball->vector.x>-2.5)&& (this->entiny_ball->vector.y<2.5 && this->entiny_ball->vector.y>-2.5)) {
			this->entiny_ball->vector.x *= 2.0;
			this->entiny_ball->vector.y *= 2.0;
			return Fall::Reset();
			//delete this;
		}
		else return false;
	}
	void Draw(sf::RenderWindow *window) {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			window->draw(*this);
		}
		else {
			this->entiny_ball->vector.x*=0.5;
			this->entiny_ball->vector.y*=0.5;
			this->_time = this->clock.getElapsedTime();
			this->setShow(false);

		}

	}
	void Destroy() {
		delete this;
	}
private:
	Entiny *entiny_paddle ,*entiny_ball;
	sf::Clock clock;
	sf::Time _time;

};