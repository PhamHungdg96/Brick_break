#pragma once
#include"Header.h"
#include"Button.h"
#include"main_game.h"
#include"main_gameover.h"
#include"main_help.h"

class main_menu:public tiny_state {
public:

	void Init(sf::RenderWindow *window);
	void Update(sf::RenderWindow *window);
	void Render(sf::RenderWindow *window);
	void Destroy(sf::RenderWindow *window);
private:
	button buton1,buton2,buton3;
	sf::Event event;
	int select=0;
	bool left_key, right_key;
	sf::Texture *texture;
	sf::Sprite *sprite;
};