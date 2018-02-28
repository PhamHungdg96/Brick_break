#pragma once
// di nguoc lai cac phim di chuyen
#include"Fall.h"
#include"Paddle.h"

class Flip :public Fall {
public:
	Flip(Paddle *entiny_paddle, float X, float Y) {
		Fall::Init("Graphic/flip.png");
		Fall::SetPosition_origin(X, Y);
		this->entiny_paddle = entiny_paddle;
	}
	void Update() {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			this->move(0,2.5);
		}
	}
	void Draw(sf::RenderWindow *window) {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y<entiny_paddle->getPosition().y)) {
			window->draw(*this);
		}
		else {
			this->entiny_paddle->setFlip(true);
			this->setShow(false);
		}

	}
	bool Reset() {
		return Fall::Reset();
		//delete this;
	}
	void Destroy() {
		delete this;
	}
private:
	Paddle *entiny_paddle;
};