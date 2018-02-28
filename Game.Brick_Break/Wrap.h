#pragma once
#include"Fall.h"
#include"Entiny.h"
#include"Paddle.h"
//di xuyen man hinh
class Wrap :public Fall {
public:
	Wrap(Paddle *entiny_paddle, float X, float Y) {
		Fall::Init("Graphic/wrap.png");
		Fall::SetPosition_origin(X, Y);
		this->entiny_paddle = entiny_paddle;
	}
	void Update() {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y < entiny_paddle->getPosition().y)) {
			this->move(0, 2.5);
		}
	}
	bool Reset() {
		return Fall::Reset();
		//delete this;
	}
	void Draw(sf::RenderWindow *window) {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y < entiny_paddle->getPosition().y)) {
			window->draw(*this);
		}
		else {
			this->entiny_paddle->setWrap(true);
			// cai dat wrap cho paddle
			this->setShow(false);

		}

	}
	void Destroy() {
		delete this;
	}
private:
	Paddle *entiny_paddle;
};