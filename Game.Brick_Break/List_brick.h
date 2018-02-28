#pragma once
#include"Entiny.h"
#include"Brick.h"
#include"Flip.h"
#include"Life.h"
#include"Long.h"
#include"Fast.h"
#include"Slow.h"
#include"Wrap.h"
#include<fstream>
#include<iostream>

class List_brick :virtual public Entiny {
public:
	List_brick(Ball *ball, Score* score, Paddle *paddle, Live *liver) {
		this->ball = ball;
		this->score = score;
		this->paddle = paddle;
		this->liver = liver;
	}
	/*void setFall(Fall *fall) {
		this->fall = fall;
	}*/

	void LoadMap(std::string filename) {
		this->i = 0;
		std::ifstream openfile(filename);
		if (openfile.is_open())
		{
			openfile >> m >> n >> this->Num_brick;
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					openfile >> MapFile[i][j];

				}
			}
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					openfile >> num_fall[i][j];
					std::cout << this->num_fall[i][j] << "  ";
				}
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << "can not open file!!!" << std::endl;
			return;
		}
	}
	void Init(sf::RenderWindow *window) {
		this->window = window;
	}
	void Init() {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (MapFile[i][j] != 0) {
					if ((int)MapFile[i][j] == 2)
						this->brick[i][j] = new Brick("Graphic/brick2.png");
					if ((int)MapFile[i][j] == 1)
						this->brick[i][j] = new Brick("Graphic/brick1.png");
					if ((int)MapFile[i][j] == 3)
						this->brick[i][j] = new Brick("Graphic/brick3.png");
					this->brick[i][j]->SetPosition_origin((float)j * 80, (float)i * 25 + 40);
					this->brick[i][j]->SetBall(ball, score);
				}
				else this->brick[i][j] = NULL;
			}
		}
	}
	void Update() {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (MapFile[i][j] > 0)
					if (this->brick[i][j]->update(MapFile[i][j])) {
						if (MapFile[i][j] <= 2) {
							MapFile[i][j]--;
							//kiem tra co fall nao ko
							/*
							1.flip
							2.life
							3.long
							4.fast
							5.slow
							6.wrap
							*/
							if (this->num_fall[i][j] > 0) {
								switch (num_fall[i][j])
								{
									//khoi tao cac fall
								case 1: this->fall[i][j] = new Flip(paddle, (float)j * 80, (float)i * 25 + 40); this->fall[i][j]->setShow(true); break;
								case 2: this->fall[i][j] = new Life(paddle, liver, (float)j * 80, (float)i * 20 + 40); this->fall[i][j]->setShow(true); break;
								case 3: this->fall[i][j] = new Long(paddle, (float)j * 80, (float)i * 25 + 40); this->fall[i][j]->setShow(true); break;
								case 4: this->fall[i][j] = new Fast(paddle, ball, (float)j * 80, (float)i * 25 + 40); this->fall[i][j]->setShow(true); break;
								case 5: this->fall[i][j] = new Slow(paddle, ball, (float)j * 80, (float)i * 25 + 40); this->fall[i][j]->setShow(true); break;
								case 6: this->fall[i][j] = new Wrap(paddle, (float)j * 80, (float)i * 25 + 40); this->fall[i][j]->setShow(true);
									break;
								default:
									break;
								}
								num_fall[i][j] = 0;
							}
							//else this->fall[i][j] = NULL;
							// sai *****

							if (MapFile[i][j] > 0) {
								this->brick[i][j] = new Brick("Graphic/brick" + std::to_string(MapFile[i][j]) + ".png");
								this->brick[i][j]->SetPosition_origin((float)j * 80, (float)i * 25 + 40);
								this->brick[i][j]->SetBall(ball, score);
							}
							this->i++;
						}

					}
				if (this->num_fall[i][j] > -1) {
					if (this->num_fall[i][j] == 0 && this->fall[i][j] != NULL) {
						if (this->fall[i][j]->getShow() == true)
							this->fall[i][j]->Update();
					}
				}
				else if (this->num_fall[i][j] == -1) {

					this->fall[i][j]->Destroy();
					this->num_fall[i][j] = -2;
				}
			}
		}
		Entiny::Update();
	}
	bool getCheckBrick() {
		return this->i < this->Num_brick;
	}
	void Draw() {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (this->brick[i][j] != NULL&&MapFile[i][j] > 0.5)
					this->window->draw(*this->brick[i][j]);
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (this->num_fall[i][j] > -1)
					if (this->num_fall[i][j] == 0 && this->fall[i][j] != NULL) {
						if (this->fall[i][j]->getShow() == true)
							this->fall[i][j]->Draw(this->window);
						else {
							if (this->fall[i][j]->Reset())
								this->num_fall[i][j] = -1;
						}
					}
			}
		}
	}
	~List_brick()
	{
		delete this->texture;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				delete this->brick[i][j];
			}
		}
	}
	int getBrick() {
		return this->Num_brick;
	}
private:
	sf::RenderWindow *window;
	Brick *brick[50][50];
	int MapFile[50][50];
	int m, n, Num_brick, i = 0, num_fall[50][50];
	Ball *ball;
	Paddle *paddle;
	Live *liver;
	sf::Texture *texture;
	Score *score;
	Fall *fall[50][50];
};