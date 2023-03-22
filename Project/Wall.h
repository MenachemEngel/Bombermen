#pragma once
#include "Inanimate.h"
#include "Constants.h"
class Wall :
	public Inanimate
{
public:
	Wall(sf::Vector2f pos, sf::Vector2f size ,sf::Color color = sf::Color::White)
		: Inanimate(pos, size ,WALL ,color)
	{
	};
	~Wall();

	virtual void collide(Object& obj, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	// collide with robot the robot go back and update position
	virtual void collide(Robot& robot, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	// collide with SmartGaurd the SmartGaurd go back and update position
	virtual void collide(SmartGaurd& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	// collide with SimpleGaurd the SimpleGaurd go back and update position
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
};

