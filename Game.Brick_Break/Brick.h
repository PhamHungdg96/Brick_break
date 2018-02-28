#pragma once
#include"Entiny.h"

class Brick :public Entiny
{
public:
	Brick(std::string filename) {
		this->Load(filename);
	}
	void SetPosition_origin(float X, float Y) {
		this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
		this->setPosition(X, Y);
	}
	void SetBall(Ball *ball, Score *score) {
		this->ball = ball;
		this->score = score;
	}
	bool update(int i) {
		if (this->check_collision(ball) && ((ball->vector.x>0 && this->getGlobalBounds().left > ball->getGlobalBounds().left) && (ball->vector.x<0 && this->getGlobalBounds().left + this->getGlobalBounds().width < ball->getGlobalBounds().left + ball->getGlobalBounds().width )
			)&& ((ball->vector.y<0 && this->getGlobalBounds().top < ball->getGlobalBounds().top) && (ball->vector.y>0 && this->getGlobalBounds().top + this->getGlobalBounds().height > ball->getGlobalBounds().top + ball->getGlobalBounds().height )
				)) {
			this->ball->vector.y *= -1;
			this->ball->vector.x *= -1;

			if (i <= 2)
				this->score->increase_point();
			this->ball->Play_Sound();
			return true;
		}
		if (this->check_collision(ball) && ((ball->vector.x>0&&this->getGlobalBounds().left > ball->getGlobalBounds().left) || (ball->vector.x<0 && this->getGlobalBounds().left + this->getGlobalBounds().width < ball->getGlobalBounds().left + ball->getGlobalBounds().width)
			)) {
			this->ball->vector.x *= -1;
			if (i <= 2)
				this->score->increase_point();
			this->ball->Play_Sound();
			return true;
		}
		if (this->check_collision(ball) && ((ball->vector.y<0 && this->getGlobalBounds().top < ball->getGlobalBounds().top) || (ball->vector.y>0 && this->getGlobalBounds().top + this->getGlobalBounds().height > ball->getGlobalBounds().top + ball->getGlobalBounds().height)
			)) {
			this->ball->vector.y *= -1;
			if (i <= 2)
				this->score->increase_point();
			this->ball->Play_Sound();
			return true;
		}
		return false;
	}
	~Brick()
	{
		delete this->texture;
	}
private:
	sf::Texture *texture;
	Ball *ball;
	Score *score;
};
