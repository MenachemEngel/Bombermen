#include "SimpleGuard.h"
#include "Constants.h"
#include "Cntroller.h"
#include "Board.h"
#include "Bomb.h"
#include "Rock.h"
#include <cstdlib>
#include <iostream>

int ccMove = 0;

SimpleGuard::~SimpleGuard()
{
}

void SimpleGuard::move(sf::RenderWindow& window, sf::Event& event, sf::Clock& clk, sf::Vector2f& rPos , Board& board)
{
	m_prePos = m_pos;
	ccMove++;
	m_pos = headleMovement(clk);
	m_rec.setPosition(m_pos);
	//check that not leave the board
	if (m_direction == RIGHT) {
		if (!board.getRec().getGlobalBounds().contains(sf::Vector2f(m_pos.x + 60.f ,m_pos.y))) {
			goBack();
			randDirection();
			m_prePos = m_pos;
		}
	}
	else if (m_direction == DOWN) {
		if (!board.getRec().getGlobalBounds().contains(sf::Vector2f(m_pos.x, m_pos.y + 60.f))) {
			goBack();
			randDirection();
			m_prePos = m_pos;
		}
	}
	else {
		if (!board.getRec().getGlobalBounds().contains(m_pos)) {
			goBack();
			randDirection();
			m_prePos = m_pos;
		}
	}
}

sf::Vector2f SimpleGuard::headleMovement(sf::Clock & clk)
{
	if (ccMove == 500) {
		randDirection();
		ccMove = 0;
	}
	switch (m_direction)
	{
	case RIGHT:
		return sf::Vector2f(m_pos.x + ((SPEED+50) * clk.getElapsedTime().asSeconds()), m_pos.y);
		break;
	case LEFT:
		return sf::Vector2f(m_pos.x - ((SPEED+50) * clk.getElapsedTime().asSeconds()) ,m_pos.y);
		break;
	case UP:
		return sf::Vector2f(m_pos.x, m_pos.y - ((SPEED+50) * clk.getElapsedTime().asSeconds()));
		break;
	case DOWN:
		return sf::Vector2f(m_pos.x, m_pos.y + ((SPEED+50) * clk.getElapsedTime().asSeconds()));
		break;
	}
	return m_pos;
}

void SimpleGuard::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
}

void SimpleGuard::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	//if (isVisible()) {
	//	//std::cout << "......." << std::endl;
	//	board.restartObjects(a ,ia ,b ,rPos);
	//}
}

void SimpleGuard::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SimpleGuard::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SimpleGuard::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SimpleGuard::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (rock.isVisible()) {
		goBack();
		randDirection();
	}
}

void SimpleGuard::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	goBack();
	randDirection();
}

void SimpleGuard::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SimpleGuard::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SimpleGuard::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (bomb.isVisible()) {
		if ((int)bomb.getTimer() == 4) {
			if (isVisible()) {
				if (Cntroller::ooSound)
					m_s.play();
				Cntroller::score += (5 * Cntroller::numOfGuards);
				unvisible();
			}
		}
	}
}
