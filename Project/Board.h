#pragma once
#include "Robot.h"
#include "Animate.h"
#include "Inanimate.h"
#include <fstream>
#include <vector>

class Board
{
public:
	Board();
	Board(sf::Vector2f pos , sf::Vector2f size);

	//read level from the file
	void readLevel(int & time, int & bomb);
	
	//update level
	void updateLevel();

	//clear the board
	void clear();

	//draw the board
	void draw(sf::RenderWindow& window);


	sf::RectangleShape getRec() const;
	sf::Vector2f getSize() const;
	void setSize(sf::Vector2f v2f);
	sf::Vector2f getPos() const;
	int getLevel() const;
	void setLevel(int l);
	void setPos(sf::Vector2f v2f);
	std::vector<std::string> getBoard();

	// Resets the objects on the board According to the initial position
	void restartObjects(std::vector<std::unique_ptr<Animate>>& animate , std::vector<std::unique_ptr<Inanimate>>& inanimate ,std::vector<std::unique_ptr<Bomb>>& b, sf::Vector2f& rPos);
	~Board();

	void printBoard();
private:
	int  m_level=1;
	std::string m_fileName = "Board.txt";
	std::fstream m_file;
	std::vector<std::string> m_board;
	sf::RectangleShape m_rec;
	sf::Vector2f m_pos ,m_size;
};

