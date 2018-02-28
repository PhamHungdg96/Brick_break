#include"main_gameover.h"
void main_gameover::Init(sf::RenderWindow *window){
	this->font = new sf::Font();
	this->font->loadFromFile("Graphic/Font.ttf");
	this->text = new sf::Text("Press ENTER to try again!", *font, 50U);
	this->text->setOrigin(this->text->getGlobalBounds().width / 2, this->text->getGlobalBounds().height / 2);
	this->text->setPosition((float)window->getSize().x / 2, (float)window->getSize().y *4/ 5);
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphic/background_over.png");
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*this->texture);
}
void main_gameover::Update(sf::RenderWindow *window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		this->Destroy(window);
		coreGame.setState(new main_game());
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		this->Destroy(window);
		coreGame.setState(new main_menu());
		return;
	}
}
void main_gameover::Render(sf::RenderWindow *window) {
	
	window->draw(*this->sprite);
	window->draw(*this->text);
}
void main_gameover::Destroy(sf::RenderWindow *window) {
	delete this->text;
	delete this->font;
}