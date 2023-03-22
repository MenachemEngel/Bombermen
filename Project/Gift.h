#pragma once
#include "Inanimate.h"
class Gift :
	public Inanimate
{
public:
	//c-tor that use his father c-tor	
	Gift(sf::Vector2f pos, sf::Vector2f size, std::string img, sf::Color color = sf::Color::White)
		: Inanimate(pos, size, img, color) {};

	//abstract collides function
	virtual void collide(Object& obj, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Robot& robot, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(SmartGaurd& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(SimpleGuard& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Door& door, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Rock& rock, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(Wall& wall, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(GiftBomb& gift, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	virtual void collide(GiftLife& gift, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia,
		std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) = 0;
	virtual void collide(Bomb& bomb, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override = 0;
	
	//defoult d-tor
	virtual ~Gift();
};

