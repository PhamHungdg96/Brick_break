#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>


class tiny_state {
public :
	virtual void Init(sf::RenderWindow* window) {}
	virtual void Update(sf::RenderWindow* window){}
	virtual void Render(sf::RenderWindow* window){}
	virtual void Destroy(sf::RenderWindow* window){}
};


class game_state {
public:
	game_state() {
		this->state = NULL;
	}
	void setWindow(sf::RenderWindow *window) {
		this->window = window;
	}
	void setState(tiny_state* state) {
		this->state = state;
		if (this->state != NULL) {
			this->state->Init(this->window);
		}
	}
	void Update() {
		if (this->state != NULL) {
			this->state->Update(this->window);
		}
	}
	void Render() {
		if (this->state != NULL) {
			this->state->Render(this->window);
		}
	}
	void Destroy() {
		delete this->state;
		//delete this->window;
	}
private:
	tiny_state *state;
	sf::RenderWindow *window;

};
extern game_state coreGame;
extern bool quitGame;