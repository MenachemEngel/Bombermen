#pragma once

//includes section
#include "Object.h"

//forward declarations
class Inanimate;
class Board;
class SmartGaurd;
class SimpleGuard;
class Robot;


//this class it abstract class that inheritor from object and hold data for his inheritors
class Animate :
	public Object
{
public:
	//c-tor that use his father c-tor
	Animate(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f startPos, std::string img ,sf::Color color = sf::Color::White)
		: Object(pos, size, img ,color) {
		m_startPos = startPos;
		m_prePos = startPos;
	};
	//Animate();
	//defoult virtual d-tor
	virtual ~Animate();

	//get & set functions
	sf::Vector2f getStartPos() const;
	void setStartPos(sf::Vector2f v2f);

	//restart to position
	void restartPos();

	//move back function
	void goBack();

	//abstract move function
	virtual void move(sf::RenderWindow& window ,sf::Event& event, sf::Clock& clk ,sf::Vector2f& rPos , Board& board) = 0;
	
	//abstract collides function
	virtual void collide(Object& obj ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
						,sf::Vector2f& rPos ,Board& board 
						, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Robot& robot ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(SmartGaurd& guard ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(SimpleGuard& guard ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Door& door ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Rock& rock ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Wall& wall ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(GiftBomb& gift ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk
							,sf::Vector2f& rPos ,Board& board 
							, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(GiftLife& gift, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
							, sf::Vector2f& rPos, Board& board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia,
							std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) = 0;
	virtual void collide(Bomb& bomb ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
						,sf::Vector2f& rPos ,Board& board 
						,std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;

protected:
	sf::Vector2f m_startPos;
	sf::Vector2f m_prePos;

};

