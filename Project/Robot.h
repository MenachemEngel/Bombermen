#pragma once

//includes section
#include "Animate.h"
#include "Constants.h"

//this class hold the data for robot
class Robot :
	public Animate
{
public:
	//c-tor that use his father c-tor
	Robot(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f startPos 
						,int bomb ,int life ,int score ,sf::Color color = sf::Color::White) 
		: Animate(pos, size, startPos ,ROBOT ,color)
	{
		m_bomb = bomb;
		m_life = life;
		m_score = score;
		m_sb.loadFromFile(ROBOT_SOUND);
		m_s.setBuffer(m_sb);
	};

	//move function
	virtual void move(sf::RenderWindow& window, sf::Event& event, sf::Clock& clk, sf::Vector2f& rPos , Board& board) override;
	

	//collides function
	virtual void collide(Object& obj, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Robot& robot, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(SmartGaurd& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(SimpleGuard& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Door& door, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Rock& rock, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Wall& wall, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(GiftBomb& gift, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(GiftLife& gift, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Bomb& bomb, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;


	//get & set functions
	int getScore()const;
	void addScore(int score);
	int getLife()const;
	void setLife(int life);
	void decLife();
	int getBomb()const;
	void setBomb(int);
	void addBombs(int bombs);
	void decBomb();

	//manage the event funnction
	sf::Vector2f heandleEvent(sf::Event& event ,sf::Clock& clk);


	//defoult d-tor
	~Robot();

private:
	int m_bomb, m_life, m_score;

};

