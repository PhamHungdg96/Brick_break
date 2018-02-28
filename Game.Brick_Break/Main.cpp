
#include"Header.h"
#include"main_menu.h"
#include<Windows.h>
#define WIN_WIDTH 640
#define WIN_HEIGHT 680

game_state coreGame;
bool quitGame = false;
int main() {

	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Brick Breaker");
	
	sf::Music music;
	/*music.openFromFile("Sounds/music_01.wav");
	music.setLoop(true);
	music.setVolume(5);
	music.play();*/

	coreGame.setWindow(&window);
	coreGame.setState(new main_menu());
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(*(new sf::Color(4, 48, 103, 100)));
		coreGame.Update();

		//window.draw(spbg);

		coreGame.Render();
		if (quitGame) {
			window.close();
		}
		window.display();
	}

	//music.stop();
	coreGame.Destroy();
return 0;
}