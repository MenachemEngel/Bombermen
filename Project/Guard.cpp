#include "Guard.h"
#include "Constants.h"


Guard::~Guard()
{
}

int Guard::getDirection() const
{
	return m_direction;
}

void Guard::setDirection(int direction)
{
	m_direction = direction;
}

void Guard::randDirection()
{
	int old = m_direction;
	while (old == m_direction)
		m_direction = rand() % 4 + 1;
}