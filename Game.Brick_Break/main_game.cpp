#include"main_game.h"
#include<sstream>
#include<string>
void main_game::Init(sf::RenderWindow *window) {

	this->font = new sf::Font();
	this->font->loadFromFile("Graphic/Font.ttf");
	this->text_lever = new sf::Text();
	this->text_lever->setFont(*this->font);
	this->bool_text_lever = true;
	this->text_lever->setCharacterSize(50U);
	//this->text_lever->setFillColor(sf::Color::);
	this->text_lever->setString("LEVER " + std::to_string((int) this->Num_state));
	this->text_lever->setPosition(window->getSize().x / 2 - this->text_lever->getGlobalBounds().width/2, window->getSize().y / 2 -this->text_lever->getGlobalBounds().height / 2);


	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();
	this->Pause = new sf::Text("Pause", *this->font, 230U);
	this->Pause->setFillColor(sf::Color::Yellow);
	this->Pause->setOrigin((float)this->Pause->getGlobalBounds().width / 2, (float)this->Pause->getGlobalBounds().height / 2);
	this->Pause->setPosition((float)window->getSize().x / 2, (float)window->getSize().y / 2 - 50);

	this->score = new Score(font, 32U);
	this->score->setPosition(0, window->getSize().y - (float)this->score->getGlobalBounds().height - 18);
	this->liver = new Live(font, 32U);
	this->liver->setPosition(this->score->getGlobalBounds().width + 80, window->getSize().y - (float)this->liver->getGlobalBounds().height - 18);

	this->Paddle_player = new Paddle();
	this->ball = new Ball(Paddle_player, liver);
	//this->fall = new Fall();
	this->list_brick = new List_brick(ball, score, Paddle_player, liver);

	this->load_map = new Load_Map(this->texture, Paddle_player, ball, list_brick);
	this->load_map->Update(this->Num_state);

	this->sprite->setTexture(*this->texture);

	this->Paddle_player->setOrigin(this->Paddle_player->getGlobalBounds().width / 2, 0);
	this->Paddle_player->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60);
	this->Paddle_player->setColor(sf::Color(234, 11, 120, 255));

	this->ball->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60 - this->ball->getGlobalBounds().height);
	this->list_brick->Init(window);
	this->list_brick->Init();
	//this->list_brick->setFall(this->fall);

}
void main_game::Update(sf::RenderWindow *window) {

	if (this->bool_text_lever == true&&this->clock.getElapsedTime().asSeconds() - this->time.asSeconds()>1) {
		this->bool_text_lever = false;
		this->clock.restart();
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Key_Right == false) {
			this->ball->Init(2.5, -2.5);
			Key_Right = true;
			Key_Left = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Key_Left == false) {
			this->ball->Init(-2.5, -2.5);
			Key_Right = true;
			Key_Left = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			this->PauseGame = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			this->PauseGame = false;
		}
		if (this->PauseGame == false) {
			// neu con mang song
			if (this->liver->getLive() > 0) {
				// neu chua chet 1 mang
				if (this->liver->getIncrease()) {
					// neu chua qua map
					if (this->list_brick->getCheckBrick()) {
						this->Paddle_player->Update();
						this->list_brick->Update();
						this->ball->Update();
						this->score->Update();
						this->liver->Update();
					}
					// neu qua map
					else {
						this->Num_state++;
						this->bool_text_lever = true;
						this->bool_time = true;
						this->text_lever->setString("LEVER " + std::to_string((int) this->Num_state));
						this->load_map->Update(this->Num_state);
						this->list_brick->Init();
						this->ball->Init(0, 0);
						Key_Right = false;
						Key_Left = false;
						this->ball->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60 - this->ball->getGlobalBounds().height);
						this->Paddle_player->setOrigin(this->Paddle_player->getGlobalBounds().width / 2, 0);
						this->Paddle_player->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60);
						this->Paddle_player->setColor(sf::Color(234, 11, 120, 255));
					}
				}
				// khi chet 1 mang ma van con so mang va so gach
				else {
					this->liver->SetGone(true);
					this->ball->Init(0, 0);
					Key_Right = false;
					Key_Left = false;
					this->ball->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60 - this->ball->getGlobalBounds().height);
					this->Paddle_player->setOrigin(this->Paddle_player->getGlobalBounds().width / 2, 0);
					this->Paddle_player->setPosition((float)window->getSize().x / 2, window->getSize().y - (float)this->Paddle_player->getGlobalBounds().height - 60);
					this->Paddle_player->setColor(sf::Color(234, 11, 120, 255));
				}
			}
			// het mang
			else {
				this->Destroy(window);
				coreGame.setState(new main_gameover());
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			this->Destroy(window);
			coreGame.setState(new main_menu());
		}
	}
	/*if (this->fall->getShow() == true && !this->fall->check_collision(this->Paddle_player))
		this->fall->move(0, 1.5);*/
}
void main_game::Render(sf::RenderWindow *window) {
	window->draw(*this->sprite);
	if (this->bool_time == true) {
		this->time = this->clock.getElapsedTime();
		this->bool_time = false;
	}
	if (this->bool_text_lever) {
		window->draw(*this->text_lever);
	}
	else {
		window->draw(*this->Paddle_player);

		this->list_brick->Draw();
		window->draw(*this->ball);

		window->draw(*this->score);
		window->draw(*this->liver);
	}
	/*if (this->fall->getShow() == true && !this->fall->check_collision(this->Paddle_player))
		window->draw(*this->fall);*/

	if (this->PauseGame == true)window->draw(*this->Pause);
}
void main_game::Destroy(sf::RenderWindow *window) {
	delete this->ball;
	delete this->Paddle_player;
	delete this->list_brick;
	delete this->load_map;
	delete this->font;
	delete this->Pause;
}