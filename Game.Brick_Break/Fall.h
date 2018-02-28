#pragma once
//#include<SFML\Graphics.hpp>
//#include"Entiny.h"


class Fall :public sf::Sprite
{
public:
	void Init(std::string a) {
		
		this->texture = new sf::Texture();
		this->texture->loadFromFile(a);
		this->setTexture(*this->texture);
	}
	bool check_collision(Entiny *entiny) {
		return this->getGlobalBounds().intersects(entiny->getGlobalBounds());
	}
	void setShow(bool show) {
		this->show = show;
	}
	bool getShow() {
		return this->show;
	}
	void SetPosition_origin(float x,float y) {
		this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
		this->setPosition(x, y);
	}
	void virtual Update() {
		//this->move(0, 1.5);
	}
	void virtual Draw(sf::RenderWindow *window){
	}
	bool virtual Reset() {
		return true;
	}
	void virtual Destroy() {

	}
private:
	sf::Texture *texture;
	Entiny *entiny;
	bool show;
};