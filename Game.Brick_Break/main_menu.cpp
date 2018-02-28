#include"main_menu.h"
#include<iostream>
#define WIN_WIDTH 640
#define WIN_HEIGHT 680

void main_menu::Init(sf::RenderWindow *window) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphic/background.png");
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*this->texture);
	buton1.setButton(WIN_WIDTH / 2-45, WIN_WIDTH *2/ 3,"Graphic/play1.png");
	buton1.setEvent(event);

	buton2.setButton(WIN_WIDTH -100,WIN_HEIGHT-100, "Graphic/quit1.png");
	buton2.setEvent(event);

	buton3.setButton(WIN_WIDTH - 200, WIN_HEIGHT - 100, "Graphic/help1.png");
	buton3.setEvent(event);
}
void main_menu::Update(sf::RenderWindow *window) {
	if (buton1.setEvent(window)||sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		this->Destroy(window);
		coreGame.setState(new main_game());
		return;
	}
	if (buton2.setEvent(window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		quitGame = true;
		return;
	}
	if (buton3.setEvent(window) || sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		this->Destroy(window);
		coreGame.setState(new main_help());
		return;
	}
}
void main_menu::Render(sf::RenderWindow *window) {
	window->draw(*this->sprite);
	buton1.setwindow(window);
	buton2.setwindow(window);
	buton3.setwindow(window);
	
}
void main_menu::Destroy(sf::RenderWindow *window) {
	delete this->sprite;
	delete this->texture;
	delete this;
}