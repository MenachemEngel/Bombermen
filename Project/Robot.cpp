#include "Robot.h"
#include "Constants.h"
#include "SimpleGuard.h"
#include "SmartGaurd.h"
#include "Rock.h"
#include "Wall.h"
#include "Bomb.h"
#include "GiftBomb.h"
#include "GiftLife.h"
#include "Door.h"
#include "Board.h"
#include "Cntroller.h"
#include <iostream>

void Robot::move(sf::RenderWindow& window, sf::Event& event, sf::Clock& clk, sf::Vector2f& rPos , Board& board)
{
	m_prePos = m_pos;
	m_pos = heandleEvent(event ,clk);
	m_rec.setPosition(m_pos);
	//check that not leave the board
	if (m_prePos.x < m_pos.x) {
		if (!board.getRec().getGlobalBounds().contains(sf::Vector2f(m_pos.x + 60.f, m_pos.y))) {
			goBack();
			m_prePos = m_pos;
		}
	}
	else if (m_prePos.y < m_pos.y) {
		if (!board.getRec().getGlobalBounds().contains(sf::Vector2f(m_pos.x, m_pos.y + 60.f))) {
			goBack();
			m_prePos = m_pos;
		}
	}
	else {
		if (!board.getRec().getGlobalBounds().contains(m_pos)) {
			goBack();
			m_prePos = m_pos;
		}
	}
	rPos = m_pos;
}


int Robot::getScore()const
{
	return m_score;
}

void Robot::addScore(int score)
{
	if (Cntroller::score > m_score) {
		m_score = Cntroller::score;
	}
	else {
		Cntroller::score = m_score;
	}
	m_score += score;
	Cntroller::score = m_score;
}

int Robot::getLife()const
{
	return m_life;
}

void Robot::setLife(int life)
{
	m_life = life;
}

int Robot::getBomb() const
{
	return m_bomb;
}

void Robot::setBomb(int bomb)
{
	m_bomb = bomb;
}

void Robot::addBombs(int bombs)
{
	if (Cntroller::bomb < m_bomb) {
		m_bomb = Cntroller::bomb;
	}
	m_bomb += bombs;
	Cntroller::bomb = m_bomb;
}

void Robot::decBomb()
{
	if (Cntroller::bomb < m_bomb) {
		m_bomb = Cntroller::bomb;
	}
	m_bomb--;
	Cntroller::bomb = m_bomb;
}

sf::Vector2f Robot::heandleEvent(sf::Event& event ,sf::Clock& clk)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			return sf::Vector2f(m_pos.x, m_pos.y - (SPEED * clk.getElapsedTime().asSeconds()));
			break;
		case sf::Keyboard::Down:
			return sf::Vector2f(m_pos.x, m_pos.y + (SPEED * clk.getElapsedTime().asSeconds()));
			break;
		case sf::Keyboard::Right:
			return sf::Vector2f(m_pos.x + (SPEED * clk.getElapsedTime().asSeconds()), m_pos.y);
			break;
		case sf::Keyboard::Left:
			return sf::Vector2f(m_pos.x - (SPEED * clk.getElapsedTime().asSeconds()), m_pos.y);
			break;
		}
	}
	return m_pos;
}

void Robot::decLife()
{
	if (Cntroller::life < m_life) {
		m_life = Cntroller::life;
	}
	else {
		Cntroller::life = m_life;
	}
	m_life--;
	Cntroller::life = m_life;
}


Robot::~Robot()
{
}

void Robot::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index ,bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a ,ia ,b ,index, nextLevel);
}

void Robot::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Robot::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (guard.isVisible()) {
		if (Cntroller::ooSound)
			m_s.play();
		board.restartObjects(a ,ia ,b ,rPos);
	}
}

void Robot::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (guard.isVisible()) {
		//std::cout << "--------" << std::endl;
		if (Cntroller::ooSound)
			m_s.play();
		board.restartObjects(a, ia, b, rPos);
	}
}

void Robot::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	nextLevel = true;
	addScore(20 * Cntroller::numOfGuards);
	Cntroller::numOfGuards = 0;
	Cntroller::numOfBombs = 0;
}

void Robot::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (rock.isVisible()) {
		goBack();
		rPos = m_pos;
	}
}

void Robot::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	goBack();
	rPos = m_pos;
}

void Robot::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia , std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (gift.isVisible()) {
		if(Cntroller::bomb >= 0)
			addBombs(PRESENT);
		gift.unvisible();
	}
}

void Robot::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia , std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (gift.isVisible()) {
		Cntroller::life++;
		gift.unvisible();
	}
}

void Robot::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if ((int)(bomb.getTimer()) == 4) {
		if (isVisible()) {
			if(Cntroller::ooSound)
				m_s.play();
			board.restartObjects(a, ia, b, rPos);
		}
	}
}
