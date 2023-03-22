#include "GiftBomb.h"
#include "Constants.h"
#include "Cntroller.h"
#include "Robot.h"
#include <iostream>

void GiftBomb::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
}

void GiftBomb::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (isVisible()) {
		if (Cntroller::ooSound)
			m_s.play();
		if(Cntroller::bomb >= 0)
			robot.addBombs(PRESENT);
		unvisible();
	}
}

void GiftBomb::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void GiftBomb::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

GiftBomb::~GiftBomb()
{
}
