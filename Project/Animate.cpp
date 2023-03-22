#include "Animate.h"


Animate::~Animate()
{
}

sf::Vector2f Animate::getStartPos() const
{
	return m_startPos;
}

void Animate::setStartPos(sf::Vector2f v2f)
{
	m_startPos = v2f;
}

void Animate::restartPos()
{
	m_pos = m_startPos;
}

void Animate::goBack()
{
	m_pos = m_prePos;
	m_rec.setPosition(m_pos);
}

