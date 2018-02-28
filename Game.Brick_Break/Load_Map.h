#pragma once
#include<iostream>
#include<istream>
#include<SFML\Graphics.hpp>

class Load_Map {
public:
	Load_Map(sf::Texture *texture, Paddle *pad, Ball *ball, List_brick *list_brick) {
		this->pad = pad;
		this->ball = ball;
		this->list_brick = list_brick;
		this->texture = texture;
	}
	void Update(int i) {
		this->ball->Load("Graphic/ball" + std::to_string(1) + ".png");
		this->pad->Load("Graphic/paddle" + std::to_string(1) + ".png");
		this->list_brick->LoadMap("Map/Map" + std::to_string(i) + ".txt");
		this->texture->loadFromFile("Graphic/background" + std::to_string((int)i % 2) + ".png");
	}
private:
	Paddle *pad;
	Ball *ball;
	List_brick *list_brick;
	sf::Texture *texture;
};