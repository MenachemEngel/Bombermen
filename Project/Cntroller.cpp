//include section
#include "Cntroller.h"
#include "Object.h"
#include "Bomb.h"
#include "GiftBomb.h"
#include "GiftLife.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "Robot.h"
#include "SimpleGuard.h"
#include "SmartGaurd.h"
#include "Constants.h"
#include <cstdlib>
#include <memory>
#include <typeinfo>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//global variables
sf::Vector2f rPos;
bool nextLevel = true;
int sBomb = 0;

//static variables
int Cntroller::score = 0;
int Cntroller::life = LIFE;
int Cntroller::bomb = 0;
int Cntroller::clockTime = 0;
int Cntroller::numOfGuards = 0;
int Cntroller::numOfBombs = 0;
bool Cntroller::pause = false;
bool Cntroller::ooSound = true;
bool Cntroller::ooMusic = true;
sf::Sound Cntroller::bombSound = sf::Sound();

//c-tor
Cntroller::Cntroller()
{
	int h = sf::VideoMode::getDesktopMode().height;
	int w = sf::VideoMode::getDesktopMode().width;
	m_window.create(sf::VideoMode(w, h), "Bomberman");
	m_ptSound.loadFromFile(SOUND);
	m_pSound.setTexture(&m_ptSound);
	m_pSound.setSize(sf::Vector2f(SIZE_OF_OBJECTS));
	m_ptMusic.loadFromFile(MUSIC);
	m_pMusic.setTexture(&m_ptMusic);
	m_pMusic.setSize(sf::Vector2f(SIZE_OF_OBJECTS));
	m_font.loadFromFile(GM_FONT);
	m_arial.loadFromFile(ARIAL);
	m_tData.setFont(m_font);
	m_tHelp.setFont(m_arial);

	m_tpp.loadFromFile(G_PLAY);
	m_pp.setSize(SIZE_OF_OBJECTS);
	m_pp.setTexture(&m_tpp);

	bombBS.loadFromFile(EXPLOSIN_SOUND);
	bombSound.setBuffer(bombBS);

	m_winBSound.loadFromFile(WIN_SOUND);
	m_winSound.setBuffer(m_winBSound);
	m_loseBSound.loadFromFile(LOSE_SOUND);
	m_loseSound.setBuffer(m_loseBSound);

	m_mMusic.openFromFile(M_MUSIC);
	m_gMusic.openFromFile(G_MUSIC);

	readHelp();

	m_mMusic.setLoop(true);
	m_mMusic.play();
}

//read level wor with the board class
void Cntroller::readLevel() {
	m_board.readLevel(clockTime ,sBomb);
	float x = (float(sf::VideoMode::getDesktopMode().width));
	float y = 80.f;
	x /= 2;
	x -= (m_board.getSize().x / 2);
	m_board.setPos(sf::Vector2f(x, y));
	newLevel();
}

//show the number level befor the level
void Cntroller::newLevel() {
	sf::Text t;
	sf::Font f;
	f.loadFromFile(GM_FONT);
	t.setFont(f);
	t.setCharacterSize(40);
	t.setFillColor(sf::Color::White);
	t.setPosition(((m_board.getPos().x + m_board.getSize().x / 2) - 60) , (m_board.getPos().y + m_board.getSize().y / 2) -30);
	t.setString("Level " + std::to_string(m_board.getLevel() - 1));
	m_window.clear(sf::Color(169, 169, 169, 255));
	m_board.draw(m_window);
	m_window.draw(t);
	m_window.display();
	Sleep(1000);
	m_clockGame.restart();
	m_time = 0;
}

//reload function
void Cntroller::button(sf::RectangleShape &rs) {
	rs.setSize(SIZE_OF_OBJECTS);
	rs.setPosition(m_board.getPos().x - 110, 100.f);
	sf::Texture ttrs;
	ttrs.loadFromFile(R);
	rs.setTexture(&ttrs);
	m_pSound.setPosition(rs.getPosition().x , rs.getPosition().y + 105);
	m_pMusic.setPosition(rs.getPosition().x , rs.getPosition().y + 205);
	m_pp.setPosition(rs.getPosition().x , rs.getPosition().y + 305);
	m_window.draw(rs);
}

//print data of the game function
void Cntroller::printData()
{
	button(m_rs);
	char c = 236;
	m_data = "Level: " + std::to_string(m_board.getLevel() - 1)
		+ "\tScore: " + std::to_string(score)
		+ "\t Lives: " + std::to_string(life);
	if (bomb < 0) {
		m_data += "\t Bombs: --";
	}
	else {
		m_data += "\t Bombs: " + std::to_string(bomb);
	}
	if (bomb < 0) {
		m_data += "\t Time: -/-";
	}
	else {
		m_data += "\t Time: " + std::to_string((int)m_time)
		+ "/" + std::to_string(clockTime);
	}
	m_tData.setString(m_data);
	m_tData.setCharacterSize(55);
	m_tData.setPosition(sf::Vector2f(((m_board.getPos().x + m_board.getSize().x / 2) - 800),5.f));
	m_tData.setFillColor(sf::Color::Black);
	m_window.draw(m_tData);
}

//general menu
void Cntroller::run()
{
		float x = (float(sf::VideoMode::getDesktopMode().width));
		float y = 80.f;
		x /= 2;
		sf::RectangleShape rs1(sf::Vector2f(500.f ,500.f));
		x -= (500.f / 2.f);
		sf::Texture tx1;
		tx1.loadFromFile(MENU_ROBOT);
		rs1.setTexture(&tx1);
		rs1.setPosition(x, y);
		sf::RectangleShape rs2(sf::Vector2f(500.f ,100.f));
		sf::Texture tx2;
		tx2.loadFromFile(FIRE);
		rs2.setTexture(&tx2);
		rs2.setPosition(x, 480.f);
		sf::RectangleShape rs3(sf::Vector2f(180.f ,180.f));
		sf::Texture tx3;
		tx3.loadFromFile(BOMB);
		rs3.setTexture(&tx3);
		rs3.setPosition(x, 400.f);
		sf::RectangleShape rs4(sf::Vector2f(600.f ,600.f));
		sf::Texture tx4;
		tx4.loadFromFile(MENU);
		rs4.setTexture(&tx4);
		rs4.setPosition(x-50, 700.f);
		m_pSound.setPosition(rs4.getPosition().x + 200, rs4.getPosition().y + 620);
		m_pMusic.setPosition(rs4.getPosition().x + 310, rs4.getPosition().y + 620);
		sf::Text t;
		sf::Text t1;
		sf::Font f;
		f.loadFromFile(FL_FONT);
		t.setFont(f);
		t1.setFont(m_font);
		t.setFillColor(sf::Color(204 ,105 ,0 ,255));
		t1.setFillColor(sf::Color::Black);
		t.setCharacterSize(100);
		t1.setCharacterSize(100);
		t.setString("BOMBERMAN");
		t1.setString("Play\nHelp\nExit");
		t.setPosition(x-85.f ,580.f);
		t1.setPosition(x+150 ,800.f);
		sf::RectangleShape m1(sf::Vector2f(600.f, 130.f));
		m1.setPosition(rs4.getPosition().x , 800.f);
		sf::RectangleShape m2(sf::Vector2f(600.f, 130.f));
		m2.setPosition(rs4.getPosition().x,930.f);
		sf::RectangleShape m3(sf::Vector2f(600.f, 130.f));
		m3.setPosition(rs4.getPosition().x, 1060.f);
		sf::RectangleShape ul1(sf::Vector2f(60.f, 10.f));
		ul1.setFillColor(sf::Color::Black);
		ul1.setPosition(x + 150, 910.f);
		sf::RectangleShape ul2(sf::Vector2f(60.f, 10.f));
		ul2.setFillColor(sf::Color::Black);
		ul2.setPosition(x + 150, 1030.f);
		sf::RectangleShape ul3(sf::Vector2f(60.f, 10.f));
		ul3.setFillColor(sf::Color::Black);
		ul3.setPosition(x + 150, 1145.f);
		sf::CircleShape cs(35 ,3);
		cs.setFillColor(sf::Color::Black);
		cs.setPosition(x + 110, 840.f);
		cs.rotate(90.f);
		sf::SoundBuffer soundBuffer;
		if (!soundBuffer.loadFromFile(MENU_SOUND))
			return;
		sf::Sound sound;
		sound.setBuffer(soundBuffer);
		sf::SoundBuffer soundBuffer1;
		sf::Sound sound1;
		if (!soundBuffer1.loadFromFile(ENTER_CHOOSE))
			return;
		sound1.setBuffer(soundBuffer1);
	while (m_window.isOpen()) {
		m_window.clear(sf::Color(169, 169, 169, 255));
		while (m_window.pollEvent(m_event)) {
			sf::Vector2f v2f = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
			if (m_event.type == sf::Event::Closed) {
				m_window.close();
			}
			else if (m_event.type == sf::Event::MouseButtonPressed) {
				if (m_event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2f v2f = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
					if (m_pSound.getGlobalBounds().contains(v2f)) {
						if (ooSound) {
							ooSound = false;
							m_ptSound.loadFromFile(UNSOUND);
						}
						else {
							ooSound = true;
							m_ptSound.loadFromFile(SOUND);
						}
					}
					else if (m_pMusic.getGlobalBounds().contains(v2f)) {
						if (ooMusic) {
							m_gMusic.setVolume(0.f);
							ooMusic = false;
							m_ptMusic.loadFromFile(UNMUSIC);
						}
						else {
							m_gMusic.setVolume(30.f);
							ooMusic = true;
							m_ptMusic.loadFromFile(MUSIC);
						}
					}
					else if (m1.getGlobalBounds().contains(v2f)) {
						if (ooSound)
							sound1.play();
						m_mMusic.stop();
						play();
						m_mMusic.setLoop(true);
						if (!ooMusic)
							m_mMusic.setVolume(0.f);
						m_pSound.setPosition(rs4.getPosition().x + 200, rs4.getPosition().y + 710);
						m_pMusic.setPosition(rs4.getPosition().x + 310, rs4.getPosition().y + 710);
						m_mMusic.play();
					}
					else if (m2.getGlobalBounds().contains(v2f)) {
						if (ooSound)
							sound1.play();
						help();
					}
					else if (m3.getGlobalBounds().contains(v2f)) {
						if (ooSound)
							sound1.play();
						m_window.close();
					}
				}
			}
			else if (m_event.type == sf::Event::MouseMoved) {
				if (m1.getGlobalBounds().contains(v2f)) {
					cs.setPosition(cs.getPosition().x , 840.f);
				}
				else if (m2.getGlobalBounds().contains(v2f)) {
					cs.setPosition(cs.getPosition().x, 960.f);
				}
				else if (m3.getGlobalBounds().contains(v2f)) {
					cs.setPosition(cs.getPosition().x, 1080.f);
				}
			}
			else if (m_event.type == sf::Event::KeyPressed) {
				switch (m_event.key.code)
				{
					case sf::Keyboard::Down:
						if(cs.getPosition().y != 1080.f)
							cs.setPosition(cs.getPosition().x , cs.getPosition().y + 120);
						if(ooSound)
							sound.play();
						break;
					case sf::Keyboard::Up:
						if(cs.getPosition().y != 840.f)
							cs.setPosition(cs.getPosition().x, cs.getPosition().y - 120);
						if (ooSound)
							sound.play();
						break;
					case sf::Keyboard::Enter:
						if (ooSound)
							sound1.play();
						if (cs.getPosition().y == 840.f) {
							m_mMusic.stop();
							play();
							m_mMusic.setLoop(true);
							if (!ooMusic)
								m_mMusic.setVolume(0.f);
							m_pSound.setPosition(rs4.getPosition().x + 200, rs4.getPosition().y + 710);
							m_pMusic.setPosition(rs4.getPosition().x + 310, rs4.getPosition().y + 710);
							m_mMusic.play();
						}else if(cs.getPosition().y == 960.f){
							help();
						}
						else {
							m_window.close();
						}
						break;
					case sf::Keyboard::P:
						if (ooSound)
							sound1.play();
						m_mMusic.stop();
						play();
						m_mMusic.setLoop(true);
						if (!ooMusic)
							m_mMusic.setVolume(0.f);
						m_pSound.setPosition(rs4.getPosition().x + 200, rs4.getPosition().y + 710);
						m_pMusic.setPosition(rs4.getPosition().x + 310, rs4.getPosition().y + 710);
						m_mMusic.play();
						break;
					case sf::Keyboard::S:
						if (ooSound) {
							ooSound = false;
							m_ptSound.loadFromFile(UNSOUND);
						}
						else {
							ooSound = true;
							sound1.play();
							m_ptSound.loadFromFile(SOUND);
						}
						break;
					case sf::Keyboard::M:
						if (ooMusic) {
							m_mMusic.setVolume(0.f);
							ooMusic = false;
							m_ptMusic.loadFromFile(UNMUSIC);
						}
						else {
							m_mMusic.setVolume(100.f);
							ooMusic = true;
							m_ptMusic.loadFromFile(MUSIC);
						}
						break;
					case sf::Keyboard::H:
						if (ooSound)
							sound1.play();
						help();
						break;
					case sf::Keyboard::E:
					case sf::Keyboard::Escape:
						if (ooSound)
							sound1.play();
						m_window.close();
						break;
				}
			}
		}
		m_window.draw(m_pSound);
		m_window.draw(m_pMusic);
		m_window.draw(rs1);
		m_window.draw(rs3);
		m_window.draw(rs2);
		m_window.draw(t);
		m_window.draw(rs4);
		m_window.draw(t1);
		m_window.draw(ul1);
		m_window.draw(ul2);
		m_window.draw(ul3);
		m_window.draw(cs);
		m_window.display();
	}
}

void Cntroller::finishGame(bool win)
{
	float x = (float(sf::VideoMode::getDesktopMode().width));
	x /= 2;
	x -= 300;
	float y = 80.f;
	m_window.clear(sf::Color(169, 169, 169, 255));

	//if win
	if (win) {
		sf::RectangleShape rs1;
		rs1.setSize(sf::Vector2f(512.f, 878.5));
		sf::Texture tt1;
		tt1.loadFromFile(R_WIN);
		rs1.setTexture(&tt1);
		rs1.setPosition(x - 50 ,y + 150);
		sf::RectangleShape rs2;
		rs2.setSize(sf::Vector2f(543.f, 721.f));
		sf::Texture tt2;
		tt2.loadFromFile(B_WIN);
		rs2.setTexture(&tt2);
		rs2.rotate(-45.f);
		rs2.setPosition(x - 550 ,y + 250);
		sf::RectangleShape rs3;
		rs3.setSize(sf::Vector2f(640.f, 623.f));
		sf::Texture tt3;
		tt3.loadFromFile(Z_WIN);
		rs3.setTexture(&tt3);
		rs3.setPosition(x + 200 ,y - 20);
		sf::Text winText;
		winText.setString("Congratulations, You won the game!\n\t\t\tYour score is: " + std::to_string(score));
		winText.setFillColor(sf::Color::Black);
		winText.setPosition(x - 700 ,y + 1000);
		winText.setFont(m_font);
		winText.setCharacterSize(100);
		if(ooSound)
			m_winSound.play();
		m_window.draw(rs2);
		m_window.draw(rs3);
		m_window.draw(rs1);
		m_window.draw(winText);
	}
	//if lost
	else {
		sf::RectangleShape rs1(sf::Vector2f(237.f * 1.5 ,299.f * 1.5));
		sf::Texture tt1;
		tt1.loadFromFile(GS);
		rs1.setTexture(&tt1);
		rs1.setPosition(x, y + 150);
		sf::RectangleShape rs2(sf::Vector2f(150.f ,150.f));
		sf::Texture tt2;
		tt2.loadFromFile(ROBOT);
		rs2.setTexture(&tt2);
		rs2.setPosition(x + 110 ,y + 350);
		rs2.rotate(-5);
		sf::Font f;
		f.loadFromFile(MD_FONT);
		sf::Text t1;
		t1.setFont(f);
		t1.setFillColor(sf::Color::Black);
		t1.setCharacterSize(100);
		t1.setString("R.I.P.");
		t1.rotate(-5);
		t1.setPosition(x + 80, y + 200);
		sf::Text t;
		t.setFont(m_font);
		t.setFillColor(sf::Color::Black);
		t.setCharacterSize(100);
		t.setString("            GAME OVER\nSorry, You lost the game!");
		t.setPosition(x - 500, y + 650);
		if (ooSound)
			m_loseSound.play();
		m_window.draw(rs1);
		m_window.draw(rs2);
		m_window.draw(t);
		m_window.draw(t1);
	}
	m_window.display();
	Sleep(5000);
	life = LIFE;
	m_board.setLevel(1);
	nextLevel = true;
	score = 0;
}

void Cntroller::restartLevel()
{
	life--;
	//create the objects again 
	createObject();
	//restart the clock
	m_clockGame.restart();
	m_time = 0;
	pause = false;
}

//void Cntroller::pause()
//{
//
//}

void Cntroller::createObject()
{
	bomb = sBomb;

	//put time in rand for correct random
	srand(time(NULL));

	//clear the vectors if they not empty
	if (!m_bomb.empty()) {
		m_bomb.clear();
	}
	if (!m_animate.empty()) {
		m_animate.clear();
	}
	if (!m_inanimate.empty()) {
		m_inanimate.clear();
	}
	numOfGuards = 0;
	int rd;
	if (!m_board.getBoard().empty())
	{
		for (int i = 0; i < m_board.getBoard().size(); i++)
		{
			for (int j = 0; j < m_board.getBoard()[i].size(); j++)
			{
				sf::Vector2f pos(m_board.getPos().x + (j * SIZE_OF_OBJECTS.x), m_board.getPos().y + (i * SIZE_OF_OBJECTS.y));
				
				//create objects by char
				switch (m_board.getBoard()[i][j])
				{
				case '/':
					m_animate.push_back(std::make_unique<Robot>(
						pos, sf::Vector2f(SIZE_OF_OBJECTS.x - 15 , SIZE_OF_OBJECTS.y - 15), pos,
						bomb, life, score)); 
					rPos = pos;
					break;
				case 'D':
					m_inanimate.push_back(std::make_unique<Door>(pos ,SIZE_OF_OBJECTS)); 
					break;
				case '!':
				{
					rd = std::rand() % 100 + 1;
					if (rd%2 == 0)
						m_animate.push_back(std::make_unique<SmartGaurd>(
							pos, sf::Vector2f(SIZE_OF_OBJECTS.x - 15, SIZE_OF_OBJECTS.y - 15),pos));
					else
						m_animate.push_back(std::make_unique<SimpleGuard>(
							pos, sf::Vector2f(SIZE_OF_OBJECTS.x - 15, SIZE_OF_OBJECTS.y - 15), pos));
					numOfGuards++;
					break;
				}
				case'@':
					m_inanimate.push_back(std::make_unique<Rock>(pos, SIZE_OF_OBJECTS));
					break;
				case'#':
					m_inanimate.push_back(std::make_unique<Wall>(pos ,SIZE_OF_OBJECTS)); 
					break;

				case'+':
					rd = std::rand() % 100 + 1;
					if(rd % 2 == 0)
						m_inanimate.push_back(std::make_unique<GiftBomb>(sf::Vector2f(pos.x + 10 ,pos.y + 10)
							,sf::Vector2f(SIZE_OF_OBJECTS.x - 20 , SIZE_OF_OBJECTS.y - 20)));
					else
						m_inanimate.push_back(std::make_unique<GiftLife>(sf::Vector2f(pos.x + 10, pos.y + 10)
							, sf::Vector2f(SIZE_OF_OBJECTS.x - 20, SIZE_OF_OBJECTS.y - 20)));
					break;

				case'&':
					rd = std::rand() % 100 + 1;
					if (rd % 2 == 0)
						m_inanimate.push_back(std::make_unique<GiftBomb>(sf::Vector2f(pos.x + 10, pos.y + 10)
							, sf::Vector2f(SIZE_OF_OBJECTS.x - 20, SIZE_OF_OBJECTS.y - 20)));
					else
						m_inanimate.push_back(std::make_unique<GiftLife>(sf::Vector2f(pos.x + 10, pos.y + 10)
							, sf::Vector2f(SIZE_OF_OBJECTS.x - 20, SIZE_OF_OBJECTS.y - 20)));
					m_inanimate.push_back(std::make_unique<Rock>(pos ,SIZE_OF_OBJECTS)); 
					break;
				}
			}
		}
	}
}

void Cntroller::play()
{
	m_gMusic.setLoop(true);
	if (!ooMusic)
		m_gMusic.setVolume(0.f);
	else
		m_gMusic.setVolume(30.f);
	m_gMusic.play();

	float ff;
	while (m_window.isOpen()) {

		//checking if need to run the game
		if (life <= 0 || (m_board.getLevel() - 1) == NUM_OF_LEVELS && nextLevel) {
			break;
		}

		//restart the clock game
		m_clockMove.restart();

		//check if read new level
		if (nextLevel) {
			readLevel();
			createObject();
			nextLevel = false;
		}
		m_window.clear(sf::Color(169 ,169 ,169 ,255));

		//manage time
		if (!pause) {
			ff = m_clockGame.restart().asSeconds();
			m_time += ff;
		}

		//check if the time of the game not finish
		if (clockTime == (int)m_time + 1) {
			restartLevel();
		}

		//print the data of game (bombs ,time , level ,life ,...)
		printData();

		//print sound picture
		m_window.draw(m_pSound);
		m_window.draw(m_pMusic);
		m_window.draw(m_pp);

		//print the board
		m_board.draw(m_window);

		//run on the objects and make they steps
		//(the index not realy in use but is to much work to delete it)
		int index = 0;
		for (auto& o : m_bomb) {
			if (o->isVisible()) {
				o->draw(m_window);
				if(!pause)
					o->collides(m_window, m_event, m_clockGame, rPos, m_board, m_animate, m_inanimate, m_bomb ,index, nextLevel);
				Bomb& b = static_cast<Bomb&>(*o);
				if (pause) {
					b.setTimer(b.getTimer());
				}
				else {
					b.setTimer(b.getTimer() + ff);
				}
				if ((int)(b.getTimer()) == 4) {
					b.explosion();
				}
				else if ((b.getTimer()) >= 5) {
					b.unvisible();
				}
			}
			index++;
		}
		index = 0;
		for (auto& o : m_inanimate) {
			if (o->isVisible()) {
				o->draw(m_window);
				if (!pause)
					o->collides(m_window, m_event, m_clockGame, rPos, m_board, m_animate, m_inanimate, m_bomb ,index, nextLevel);
				index++;
			}
		}
		index = 0;
		for (auto& o : m_animate) {
			if (o->isVisible()) {
				o->draw(m_window);
				if (!pause) {
					o->move(m_window, m_event, m_clockMove, rPos, m_board);
					o->collides(m_window, m_event, m_clockGame, rPos, m_board, m_animate, m_inanimate, m_bomb, index, nextLevel);
				}
			}
			index++;
		}
		
		//manage the event
		while (m_window.pollEvent(m_event)) {
			if (m_event.type == sf::Event::Closed) {
				m_window.close();
			}
			if (m_event.type == sf::Event::MouseButtonPressed) {
				if (m_event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2f v2f = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
					if (m_pSound.getGlobalBounds().contains(v2f)) {
						if (ooSound) {
							ooSound = false;
							m_ptSound.loadFromFile(UNSOUND);
						}
						else {
							ooSound = true;
							m_ptSound.loadFromFile(SOUND);
						}
					}
					else if (m_pMusic.getGlobalBounds().contains(v2f)) {
						if (ooMusic) {
							m_gMusic.setVolume(0.f);
							ooMusic = false;
							m_ptMusic.loadFromFile(UNMUSIC);
						}
						else {
							m_gMusic.setVolume(30.f);
							ooMusic = true;
							m_ptMusic.loadFromFile(MUSIC);
						}
					}
					else if (m_rs.getGlobalBounds().contains(v2f)) {
						restartLevel();
					}
					else if (m_pp.getGlobalBounds().contains(v2f)) {
						if (pause) {
							m_clockGame.restart();
							pause = false;
							m_tpp.loadFromFile(G_PLAY);
						}
						else {
							m_time += m_clockGame.getElapsedTime().asSeconds();
							pause = true;
							m_tpp.loadFromFile(G_PAUSE);
						}
					}
				}
			}
			if (m_event.type == sf::Event::KeyPressed) {
				switch(m_event.key.code) {

					//put bomb
					case sf::Keyboard::B:
						if (!pause) {
							if (bomb != 0) {
								numOfBombs++;
								putBomb();
							}
						}
						break;
						//reload the levele
					case sf::Keyboard::R:
						restartLevel();
						break;
						//back to menu
					case sf::Keyboard::S:
						if (ooSound) {
							ooSound = false;
							m_ptSound.loadFromFile(UNSOUND);
						}
						else {
							ooSound = true;
							m_ptSound.loadFromFile(SOUND);
						}
						break;
					case sf::Keyboard::M:
						if (ooMusic) {
							m_gMusic.setVolume(0.f);
							ooMusic = false;
							m_ptMusic.loadFromFile(UNMUSIC);
						}
						else {
							m_gMusic.setVolume(30.f);
							ooMusic = true;
							m_ptMusic.loadFromFile(MUSIC);
						}
						break;
					case sf::Keyboard::Space:
						if (pause){
							m_clockGame.restart();
							pause = false;
							m_tpp.loadFromFile(G_PLAY);
						}
						else {
							m_time += m_clockGame.getElapsedTime().asSeconds();
							pause = true;
							m_tpp.loadFromFile(G_PAUSE);
						}
						break;
					case sf::Keyboard::Escape:
						m_board.setLevel(1);
						nextLevel = true;
						score = 0;
						life = LIFE;
						m_gMusic.stop();
						return;
						break;
				}
			}
		}
		m_window.display();
	}
	//check if the win
	if (life <= 0) {
		finishGame(false);
	}
	else if(m_board.getLevel() >= NUM_OF_LEVELS){
		finishGame(true);
	}
	m_gMusic.stop();
}

//hold and print the data of help
void Cntroller::help()
{
	m_tHelp.setString(m_help);
	m_tHelp.setFillColor(sf::Color::Black);
	m_tHelp.setCharacterSize(50);
	sf::Text t;
	t.setString("Arrow up to up\nArrow doun to down\nTo back to menu press 'Enter' or 'Esc'");
	t.setFillColor(sf::Color::Red);
	t.setCharacterSize(40);
	t.setOutlineColor(sf::Color::Red);
	t.setOutlineThickness(1);
	t.setPosition(0.f ,0.f);
	t.setFont(m_arial);
	float x = 0, y = 0;
	bool v = true;
	while (m_window.isOpen()) {
		while (m_window.pollEvent(m_event)) {
			if (m_event.type == sf::Event::KeyPressed) {
				switch(m_event.key.code){
					case sf::Keyboard::Enter:
					case sf::Keyboard::Escape:
						t.setString("");
						return;
						break;
					case sf::Keyboard::Up:
						y += 10;
						v = false;
						break;
					case sf::Keyboard::Down:
						y -= 10;
						v = false;
						break;
				}
			}
			else if (m_event.type == sf::Event::Closed) {
				m_window.close();
			}
			
		}
		m_window.clear(sf::Color(169, 169, 169, 255));
		if (v) {
			m_window.draw(t);
		}
		m_tHelp.setPosition(x, y);
		m_window.draw(m_tHelp);
		m_window.display();
	}
	t.setString("");
}

//read help file
void Cntroller::readHelp()
{
	std::string str;
	m_fHelp.open(HELP);
	if(m_fHelp.is_open()) {
		char c;
		while (!m_fHelp.eof()) {
			while (m_fHelp.get(c)) {
				m_help += c;
			}
		}
		m_fHelp.close();
	}
	else {
		m_help = "ERROR: Cannot find the text!";
	}
	m_tData.setString(m_help);
}

//put bomb
void Cntroller::putBomb()
{
	if (bomb != 0) {
		if(bomb > 0)
			bomb--;
		m_bomb.push_back(std::make_unique<Bomb>(rPos, sf::Vector2f(SIZE_OF_OBJECTS.x - 10 , SIZE_OF_OBJECTS.y - 10)));
	}
}

//d-tor
Cntroller::~Cntroller()
{
}
