#include "Bomb.h"
#include "Constants.h"
#include "GiftBomb.h"
#include "SimpleGuard.h"
#include "SmartGaurd.h"
#include "Robot.h"
#include "Rock.h"
#include "Cntroller.h"
#include <Windows.h>

float Bomb::getTimer() const
{
	return m_timer;
}

void Bomb::setTimer(float f)
{
	m_timer = f;
}

void Bomb::explosion()
{
	if (m_explo) {
		if(Cntroller::ooSound)
			Cntroller::bombSound.play();
		m_rec.setScale(sf::Vector2f(3, 3));
		m_rec.setPosition(m_rec.getPosition().x - 90, m_rec.getPosition().y - 90);
		m_texture.loadFromFile(EXPLOSION);
		m_explo = false;
	}
	m_rec.setTextureRect(sf::IntRect(j ,i ,64 ,64));
	m_texture.setRepeated(true);
	m_rec.setFillColor(sf::Color(255 ,255 ,255 ,m_a));
	if (c == 5) {
		j += 65;
		if (j == 260) {
			j = 0;
			i += 65;
		}
		////if(m_a>0)
		//	//m_a -= 1;
		if (i == 260) {
			m_a = 0;
		}
		c = 0;
	}
	c++;
}

void Bomb::collide(Object & obj, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	obj.collide(*this, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
}

void Bomb::collide(Robot & robot, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if ((int)getTimer() == 4) {
		board.restartObjects(a ,ia ,b ,rPos);
	}
}

void Bomb::collide(SmartGaurd & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if ((int)getTimer() == 4) {
		Cntroller::score += (5 * Cntroller::numOfGuards);
		guard.unvisible();
	}
}

void Bomb::collide(SimpleGuard & guard, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if ((int)getTimer() == 4) {
		Cntroller::score += (5 * Cntroller::numOfGuards);
		guard.unvisible();
	}
}

void Bomb::collide(Door & door, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Bomb::collide(Rock & rock, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	if ((int)getTimer() == 4) {
		if (rock.isVisible()) {
			rock.unvisible();
		}
	}
}

void Bomb::collide(Wall & wall, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Bomb::collide(GiftBomb & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Bomb::collide(GiftLife & gift, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
}

void Bomb::collide(Bomb & bomb, sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	
}



Bomb::~Bomb()
{
}
