#include "SmartGaurd.h"
#include "Constants.h"
#include "Cntroller.h"
#include "Board.h"
#include "Bomb.h"
#include "Rock.h"
#include <algorithm>

int cMove = 0;

SmartGaurd::~SmartGaurd()
{
}

void SmartGaurd::move(sf::RenderWindow& window, sf::Event& event, sf::Clock& clk, sf::Vector2f& rPos ,Board& board)
{	
	m_prePos = m_pos;
	cMove++;
	sf::RectangleShape h(sf::Vector2f(SIZE_OF_OBJECTS.x ,(board.getSize().y)));
	//h.setFillColor(sf::Color::Transparent);
	h.setPosition(rPos.x, 50.f);
	sf::RectangleShape w(sf::Vector2f((board.getSize().x) ,SIZE_OF_OBJECTS.y));
	//w.setFillColor(sf::Color::Transparent);
	w.setPosition((((float(sf::VideoMode::getDesktopMode().width))/2)- (board.getSize().x / 2)), rPos.y);
	//window.draw(h);
	//window.draw(w);
	if (h.getGlobalBounds().intersects(m_rec.getGlobalBounds())) {
		if (m_pos.y >= rPos.y) {
			m_direction = UP;
		}
		else {
			m_direction = DOWN;
		}
	}
	else if (w.getGlobalBounds().intersects(m_rec.getGlobalBounds())) {
		if (m_pos.x >= rPos.x) {
			m_direction = LEFT;
		}
		else {
			m_direction = RIGHT;
		}
	}
	m_pos = headleMovement(clk);
	m_rec.setPosition(m_pos);
	//check that not leave the board
	if (m_direction == RIGHT) {
		if (!board.getRec().getGlobalBounds().contains(sf::Vector2f(m_pos.x + 60.f, m_pos.y))) {
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

sf::Vector2f SmartGaurd::headleMovement(sf::Clock & clk)
{
	if (cMove == 1000) {
		randDirection();
		cMove = 0;
	}
	switch (m_direction)
	{
	case RIGHT:
		return sf::Vector2f(m_pos.x + (SPEED * clk.getElapsedTime().asSeconds()), m_pos.y);
		break;
	case LEFT:
		return sf::Vector2f(m_pos.x - (SPEED * clk.getElapsedTime().asSeconds()), m_pos.y);
		break;
	case UP:
		return sf::Vector2f(m_pos.x, m_pos.y - (SPEED * clk.getElapsedTime().asSeconds()));
		break;
	case DOWN:
		return sf::Vector2f(m_pos.x, m_pos.y + (SPEED * clk.getElapsedTime().asSeconds()));
		break;
	}
	return m_pos;
}

void SmartGaurd::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
}

void SmartGaurd::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	/*if (isVisible()) {
		board.restartObjects(a ,ia ,b ,rPos);
	}*/
}

void SmartGaurd::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SmartGaurd::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SmartGaurd::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SmartGaurd::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (rock.isVisible()) {
		goBack();
		randDirection();
	}
}

void SmartGaurd::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	goBack();
	randDirection();
}

void SmartGaurd::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SmartGaurd::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void SmartGaurd::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
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

