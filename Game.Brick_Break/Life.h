#include"Fall.h"
#include"Live.h"
#include"Entiny.h"
#include<iostream>
// them mot lan choi neu chet
class Life :public Fall {
public:
	Life(Entiny *entiny_paddle, Live *live, float X, float Y) {
		Fall::Init("Graphic/life.png");
		Fall::SetPosition_origin(X, Y);
		this->live = live;
		this->entiny_paddle = entiny_paddle;
	}
	void Update() {
		if (!(this->check_collision(entiny_paddle) && this->getPosition().y < entiny_paddle->getPosition().y)) {
			this->move(0, 2.5);
		}
	}
	void Draw(sf::RenderWindow *window) {
		if (!(Fall::check_collision(entiny_paddle) && this->getPosition().y < entiny_paddle->getPosition().y)) {
			window->draw(*this);
		}
		else {
			this->live->Inc();
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
	Live *live;
	Entiny *entiny_paddle;
};