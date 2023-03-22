#include "Rock.h"
#include "Constants.h"
#include "Robot.h"
#include "SimpleGuard.h"
#include "SmartGaurd.h"
#include "Bomb.h"
#include <iostream>

Rock::~Rock()
{
}

void Rock::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
}

void Rock::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (isVisible()) {
		robot.goBack();
		rPos = robot.getPos();
	}
}

void Rock::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (isVisible()) {
		guard.goBack();
		guard.randDirection();
	}
}

void Rock::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (isVisible()) {
		guard.goBack();
		guard.randDirection();
	}
}

void Rock::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Rock::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Rock::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Rock::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Rock::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Rock::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if (bomb.isVisible() && (int)bomb.getTimer() == 4) {
		if (isVisible()) {
			unvisible();
		}
	}
}
