#include "Board.h"
#include "Bomb.h"
#include "Cntroller.h"
#include "Constants.h"
#include <ctime>
#include <iostream>
#include <sstream> 
#include <typeinfo> 

Board::Board()
{
	m_rec.setFillColor(sf::Color(0, 153, 0, 255));
}

Board::Board(sf::Vector2f pos, sf::Vector2f size)
{
	m_rec.setFillColor(sf::Color(0 ,153 ,0 ,255));
	m_rec.setPosition(pos);
	m_rec.setSize(size);
}

void Board::readLevel(int & time , int & bomb)
{
	m_board.clear();
	std::istringstream iss;
	std::string line;
	bool firstLine = true;
	std::cout << __func__ << std::endl;
	updateLevel();
	//m_fileName = "Board4.txt";
	m_file.open(m_fileName);
	if (!m_file.is_open())
	std::cout << m_fileName << std::endl;
		while (!m_file.eof())
		{
			std::getline(m_file, line);
			if (firstLine)
			{
				iss.str(line);
				iss >> m_size.x >> m_size.y >> time >> bomb;
				m_size.x *= SIZE_OF_OBJECTS.x;
				m_size.y *= SIZE_OF_OBJECTS.y;
				std::cout << m_size.x << " " << m_size.y << " " << time << " " << bomb << std::endl;
				firstLine = false;
			}
			else
			{
				m_board.push_back(line);
			}
		}
	printBoard();
	m_file.close();
}

void Board::printBoard() {
	for (std::string str : m_board) {
		std::cout << str << std::endl;
	}
	std::cout << "board printing finished!" << std::endl;
}

void Board::updateLevel()
{
	m_fileName = "Board" + std::to_string(m_level) + ".txt" ;
	m_level++;
}

void Board::clear()
{
	m_board.clear();
}

void Board::draw(sf::RenderWindow & window)
{
	m_rec.setSize(m_size);
	m_rec.setOutlineColor(sf::Color::Black);
	m_rec.setOutlineThickness(10);
	m_rec.setPosition(m_pos);
	window.draw(m_rec);
}

sf::RectangleShape Board::getRec() const
{
	return m_rec;
}

sf::Vector2f Board::getSize() const
{
	return m_size;
}

void Board::setSize(sf::Vector2f v2f)
{
	m_size = v2f;
}

sf::Vector2f Board::getPos() const
{
	return m_pos;
}

int Board::getLevel() const
{
	return m_level;
}

void Board::setLevel(int l)
{
	m_level = l;
}

void Board::setPos(sf::Vector2f v2f)
{
	m_pos = v2f;
}

std::vector<std::string> Board::getBoard()
{
	return m_board;
}

void Board::restartObjects(std::vector<std::unique_ptr<Animate>>& animate, std::vector<std::unique_ptr<Inanimate>>& inanimate ,std::vector<std::unique_ptr<Bomb>>& b ,sf::Vector2f& rPos)
{
	for (auto& a : animate) {
		a->restartPos();
	}
	int i = 0;
	for (auto& bomb : b) {
		//sf::RectangleShape rs(SIZE_OF_OBJECTS);
		//rs.setPosition(rPos);
		//if (bomb->getRec().getGlobalBounds().intersects(rs.getGlobalBounds())) {
			bomb->unvisible();
			Cntroller::numOfBombs--;
		//}
		i++;
	}
	Cntroller::life--;
	
}

Board::~Board()
{
}
