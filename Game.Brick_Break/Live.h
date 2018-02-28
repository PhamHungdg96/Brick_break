#pragma once
#include<SFML\Graphics.hpp>
class Live :public sf::Text {
public:
	Live(sf::Font *font, unsigned size) :sf::Text("Live", *font, size) {
		this->value = 3;
		this->gone = true;
	}
	void SetGone(bool gone) {
		this->gone = gone;
	}
	void Inc() {
		this->value++;
	}
	int getLive() {
		return this->value;
	}
	bool getIncrease() {
		return this->gone;
	}
	void increase_point() {
		if (this->gone == true)
			this->value--;
	}
	void Update() {
		this->setString("Live: " + std::to_string(this->value));
	}
private:
	int value;
	bool gone;
};