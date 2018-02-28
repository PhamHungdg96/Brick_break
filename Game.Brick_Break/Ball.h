//#pragma one
#include"Paddle.h"
#include"Live.h"
#include<SFML\Audio.hpp>
class Ball:public Entiny {
public:
	Ball();
	Ball(Entiny *, Live *);
	void Init(float, float);
	void Update();
	void SetMove(float x, float y);
	~Ball()
	{
		delete this->live;
		delete this->buffer;
		delete this->sound;
	}
	void Play_Sound();
private:
	Entiny *entiny;
	Live *live;
	sf::SoundBuffer *buffer;
	sf::Sound *sound;
};