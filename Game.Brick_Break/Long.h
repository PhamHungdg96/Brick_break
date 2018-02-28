#pragma once
#include"Fall.h"
#include"Entiny.h"
// thanh dai ra
class Long :public Fall {
public:
	Long(Entiny *entiny_paddle, float X, float Y) {
		Fall::Init("Graphic/long.png");
		Fall::SetPosition_origin(X, Y);
		this->entiny_paddle = entiny_paddle;
	}
	void Update() {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			this->move(0, 2.5);
		}
	}
	bool Reset() {
		if ((float)this->clock.getElapsedTime().asSeconds()-(float)this->_time.asSeconds() >= 10) {
			entiny_paddle->setScale(-1, 1);
			entiny_paddle->setScale(1, 1);
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
			entiny_paddle->setScale(-1.2, 1);
			entiny_paddle->setScale(1.2, 1);
			this->_time = this->clock.getElapsedTime();
			this->setShow(false);
			
		}

	}
	void Destroy() {
		delete this;
	}
private:
	Entiny *entiny_paddle;
	sf::Clock clock;
	sf::Time _time;

};