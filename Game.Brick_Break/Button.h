#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>

class button {
public:
	void setButton(float x, float y, std::string a) {
		this->x = x; this->y = y;
		this->texture.loadFromFile(a);
		this->sprite.setTexture(this->texture);
		this->sprite.setPosition(x, y);
		this->sprite.setColor(sf::Color::White);
	}
	bool setEvent(sf::RenderWindow *window) {
		float X = (float)sf::Mouse::getPosition().x - window->getPosition().x-7;
		
		float Y = (float)sf::Mouse::getPosition().y - window->getPosition().y-25;
		if ((X > this->x && X < this->x + this->sprite.getGlobalBounds().width) && (Y > this->y&&Y < this->y + this->sprite.getGlobalBounds().height)) {
			this->sprite.setColor(sf::Color::Cyan);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return true;
			}
		}
		else {
			this->sprite.setColor(sf::Color::White);
		}
		return false;
	}
	void setEvent(sf::Event event) {
		this->event = event;
	}
	void setwindow(sf::RenderWindow *window) {
		this->window = window;
		this->window->draw(sprite);
	}
	~button()
	{
		//delete this;
	}
private:
	float x, y,width,height;
	sf::Event event;
	sf::RenderWindow *window;
	sf::Texture texture;
	sf::Sprite sprite;
};