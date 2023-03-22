#pragma once
#include "Inanimate.h"
#include "Constants.h"
#include <SFML/Audio.hpp>

class Bomb :
	public Inanimate
{
public:
	Bomb(sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::White)
		: Inanimate(pos, size, BOMB ,color) {
		m_font.loadFromFile(BT_FONT);
		m_text.setFont(m_font);
		m_text.setFillColor(sf::Color::White);
		m_text.setCharacterSize(20);
		m_text.setPosition(m_pos.x + 20.f, m_pos.y + 20.f);
		m_timer = 0;
	};

	// return the time
	float getTimer() const;
	void setTimer(float f);

	// draw the explosion
	void explosion();
	
	virtual void collide(Object& obj, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	// collide with robot delete robot if time = 0
	virtual void collide(Robot& robot, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	//  collide with SmartGaurd delete SmartGaurd if time = 0
	virtual void collide(SmartGaurd& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	
	//  collide with SimpleGuard delete SimpleGuard if time = 0
	virtual void collide(SimpleGuard& guard, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;
	virtual void collide(Door& door, sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
		, sf::Vector2f& rPos, Board& board
		, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, std::vector<std::unique_ptr<Bomb>>& b, int index, bool &nextLevel) override;

	//  collide with Rock delete Rock if time = 0
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

	~Bomb();
private:
	float m_timer;
	sf::Font m_font;
	sf::Text m_text;
	bool m_explo = true;
	int m_a = 200;
	int i = 0 ,j = 0 ,c = 0 ,t = 0;
};

