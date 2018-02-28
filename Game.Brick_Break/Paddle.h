#pragma once
#include"Entiny.h"

class Paddle :public Entiny {
public:
	Paddle();
	void Update();
	void SetBall(Entiny *ball) {
		this->ball = ball;
	}
	void setFlip(bool flip);
	void setWrap(bool wrap);
	void setSpeed(int speed) {
		this->speed = speed;
	}
private:
	Entiny *ball;
	bool flip;
	bool wrap;
	int speed = 3;
};