#pragma once
// bong di cham lai
#include"Fall.h"
#include"Live.h"
#include"Entiny.h"
#include<iostream>
// them mot lan choi neu chet
class Fast :public Fall {
public:
	Fast(Paddle *entiny_paddle, Entiny *entiny_ball, float X, float Y) {
		Fall::Init("Graphic/fast.png");
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
		return Fall::Reset();
	}
	void Draw(sf::RenderWindow *window) {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			window->draw(*this);
		}
		else {
			this->entiny_paddle->setSpeed(6);
			//this->_time = this->clock.getElapsedTime();
			this->setShow(false);

		}

	}
	void Destroy() {
		delete this;
	}
private:
	Paddle *entiny_paddle;
	Entiny *entiny_ball;
	sf::Clock clock;
	sf::Time _time;

};