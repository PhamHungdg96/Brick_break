#pragma once
#include<iostream>
#include<string.h>
#include"Header.h"
#include"main_menu.h"
#include"main_gameover.h"
#include"Entiny.h"
#include"Paddle.h"
#include"Ball.h"
#include"Live.h"
#include"Score.h"
#include"Fall.h"
#include"Brick.h"
#include<Windows.h>
#include"List_brick.h"
#include"Load_Map.h"


class main_game :public tiny_state {
public:

	void Init(sf::RenderWindow *window);
	void Update(sf::RenderWindow *window);
	void Render(sf::RenderWindow *window);
	void Destroy(sf::RenderWindow *window);
	main_game getState() {
		return *this;
	}
private:
	Paddle *Paddle_player;
	Ball *ball;
	List_brick *list_brick;
	Score *score;
	Live *liver;
	Load_Map *load_map;
	sf::Text *Pause,*text_lever;
	sf::Font *font;
	int live = 5;
	bool PauseGame = false, Key_Left = false, Key_Right = false;
	Fall *fall;
	sf::Texture *texture;
	sf::Sprite *sprite;
	int Num_state=1;
	bool bool_text_lever,bool_time=true;
	sf::Clock clock;
	sf::Time time;
};