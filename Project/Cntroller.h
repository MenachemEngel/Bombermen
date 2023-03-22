#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Board.h"
#include "Inanimate.h"
#include "Animate.h"

class Cntroller
{
public:
	Cntroller();
	void createObject();
	void run();
	void play();
	void help();
	void readHelp();
	void readLevel();
	void putBomb();
	void newLevel();
	void button(sf::RectangleShape &rs);
	void printData();
	void finishGame(bool win);
	void restartLevel();
	//void pause();
	~Cntroller();

	static int bomb, score, life, clockTime ,numOfGuards , numOfBombs;
	static bool pause ,ooSound ,ooMusic;
	static sf::Sound bombSound;
	sf::SoundBuffer bombBS;

private:
	std::vector<std::unique_ptr<Inanimate>> m_inanimate;
	std::vector<std::unique_ptr<Animate>> m_animate;
	std::vector<std::unique_ptr<Bomb>> m_bomb;
	Board m_board;
	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Clock m_clockGame ,m_clockMove;
	float m_time;
	std::string m_data;
	std::string m_help;
	sf::Text m_tData;
	sf::Text m_tHelp;
	sf::Font m_font;
	sf::Font m_arial;
	std::fstream m_fHelp;
	sf::RectangleShape m_pSound;
	sf::Texture m_ptSound;
	sf::RectangleShape m_pMusic;
	sf::Texture m_ptMusic;

	sf::RectangleShape m_rs;
	
	sf::RectangleShape m_pp;
	sf::Texture m_tpp;

	sf::Sound m_winSound;
	sf::Sound m_loseSound;
	sf::SoundBuffer m_winBSound;
	sf::SoundBuffer m_loseBSound;

	sf::Music m_mMusic, m_gMusic;
};