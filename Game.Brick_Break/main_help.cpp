#include"main_help.h"
void main_help::Init(sf::RenderWindow *window) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphic/help.png");
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*this->texture);
}
void main_help::Update(sf::RenderWindow *window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		this->Destroy(window);
		coreGame.setState(new main_menu());
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		this->Destroy(window);
		coreGame.setState(new main_menu());
		return;
	}
}
void main_help::Render(sf::RenderWindow *window) {

	window->draw(*this->sprite);
}
void main_help::Destroy(sf::RenderWindow *window) {
	delete this->texture;
	delete this->sprite;
}