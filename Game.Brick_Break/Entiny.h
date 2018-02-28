#pragma once

#include<SFML\Graphics.hpp>

class Entiny :public sf::Sprite {
public:
	Entiny() {
		this->texture = new sf::Texture();
	}
	void Load(std::string filename) {
		if (!texture->loadFromFile(filename))return;
		else {
			this->setTexture(*this->texture);
		}
	}
	virtual void Update() {
		this->move(this->vector);
	}
	bool check_collision(Entiny *entiny) {
		return this->getGlobalBounds().intersects(entiny->getGlobalBounds());
	}
	~Entiny()
	{
		delete this->texture;
	}
private:
	sf::Texture *texture;
public:
	sf::Vector2f vector;
	
};