#include "Object.h"
#include <iostream>
#include "Constants.h"
#include "Animate.h"
#include "Inanimate.h"

Object::Object()
{
}

Object::Object(sf::Vector2f pos, sf::Vector2f size, std::string img, sf::Color color)
{
	m_pos = pos;
	m_size = size;
	m_color = color;
	/*std::cout << "Pos (" << pos.x << "," << pos.y << ")" << std::endl;
	std::cout << "Size (" << size.x << "," << size.y << ")" << std::endl;
	std::cout << "Color (" << color.r << "," << color.g << "," << color.b << "," << color.a << ")" << std::endl;*/
	m_rec.setSize(size);
	m_rec.setFillColor(m_color);
	m_rec.setPosition(m_pos);
	m_texture.loadFromFile(img);
	m_rec.setTexture(&m_texture ,true);
	m_visible = true;
}


Object::~Object()
{
}

sf::Vector2f Object::getPos() const
{
	return m_pos;
}

void Object::setPos(sf::Vector2f v2f)
{
	m_pos = v2f;
}

sf::Vector2f Object::getSize() const
{
	return m_size;
}

void Object::setSize(sf::Vector2f v2f)
{
	m_size = v2f;
}

sf::Texture Object::getTexture() const
{
	return m_texture;
}

void Object::setTexture(sf::Texture texture)
{
	m_texture = texture;
}

sf::RectangleShape Object::getRec() const
{
	return m_rec;
}

void Object::setrec(sf::RectangleShape rec)
{
	m_rec = rec;
}

sf::Color Object::getColor() const
{
	return m_color;
}

void Object::setColor(sf::Color color)
{
	m_color = color;
}

bool Object::isVisible() const
{
	return m_visible;
}

void Object::unvisible()
{
	m_visible = false;
}

void Object::visible()
{
	m_visible = true;
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_rec);
}

void Object::collides(sf::RenderWindow & window, sf::Event & event, sf::Clock & clk, sf::Vector2f & rPos, Board & board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia , std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel)
{
	for (auto& o : a)
	{
		// Don't collide with ourselves
		if (this == o.get())
		{
			continue;
		}
		if (m_rec.getGlobalBounds().intersects(o->m_rec.getGlobalBounds()))
		{
			collide(*o ,window ,event ,clk ,rPos ,board ,a ,ia ,b ,index ,nextLevel);
		}
	}

	for (auto& o : ia)
	{
		// Don't collide with ourselves
		if (this == o.get())
		{
			continue;
		}
		if (m_rec.getGlobalBounds().intersects(o->m_rec.getGlobalBounds()))
		{
			collide(*o, window, event, clk, rPos, board, a, ia, b, index, nextLevel);
		}
	}
}