#pragma once

#include"Header.h"
#include"main_menu.h"
class main_help :public tiny_state {
public:
	void Init(sf::RenderWindow *window);
	void Update(sf::RenderWindow *window);
	void Render(sf::RenderWindow *window);
	void Destroy(sf::RenderWindow *window);
private:
	sf::Texture *texture;
	sf::Sprite *sprite;
};