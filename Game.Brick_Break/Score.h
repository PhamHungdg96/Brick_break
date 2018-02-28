#pragma once
#include<SFML\Graphics.hpp>

class Score :public sf::Text {
public:
	Score(sf::Font *font, unsigned size) :sf::Text("Score", *font, size) {
		this->value = 0;
	}
	//so lan cham
	void increase_point() {
		this->value++;
	}
	int getScore() {
		return this->value;
	}
	void Update() {
		this->setString("Score: " + std::to_string(this->value));
	}
private:
	int value;

};