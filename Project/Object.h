#pragma once

//includes section
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <memory>

//forward declarations
class Board;
class Robot;
class SmartGaurd;
class SimpleGuard;
class Door;
class Rock;
class Wall;
class GiftBomb;
class GiftLife;
class Bomb;
class Animate;
class Inanimate;

//this class it abstract class it hold the data for each inheritor class
class Object
{
public:
	//defoalt c-tor & d-tor
	Object();
	virtual ~Object();

	//c-tor that get parmeters for init the filds
	Object(sf::Vector2f pos, sf::Vector2f size, std::string img ,sf::Color color = sf::Color::White);

	//get & set functions
	sf::Vector2f getPos() const;
	void setPos(sf::Vector2f v2f);
	sf::Vector2f getSize() const;
	void setSize(sf::Vector2f v2f);
	sf::Texture getTexture() const;
	void setTexture(sf::Texture texture);
	sf::RectangleShape getRec() const;
	void setrec(sf::RectangleShape rec);
	sf::Color getColor() const;
	void setColor(sf::Color color);

	//functions that Tell if the object it still part of the game
	bool isVisible() const;
	void unvisible();
	void visible();

	//function that get window and drow the object on the window
	void draw(sf::RenderWindow& window);


	//abstract collides function
	virtual void collide(Object& obj ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
						,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a , std::vector<std::unique_ptr<Inanimate>>& ia, 
						std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(Robot& robot ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(SmartGaurd& guard ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(SimpleGuard& guard ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(Door& door ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(Rock& rock ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(Wall& wall ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;
	virtual void collide(GiftBomb& gift ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b,int index, bool &nextLevel) = 0;
	virtual void collide(GiftLife& gift ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk
							,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
							std::vector<std::unique_ptr<Bomb>>& b,int index, bool &nextLevel) = 0;
	virtual void collide(Bomb& bomb ,sf::RenderWindow& window ,sf::Event& event ,sf::Clock& clk 
						,sf::Vector2f& rPos ,Board& board , std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia, 
						std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel) = 0;

	//function that manage the collides function
	void collides(sf::RenderWindow& window, sf::Event& event, sf::Clock& clk
			, sf::Vector2f& rPos, Board& board, std::vector<std::unique_ptr<Animate>>& a, std::vector<std::unique_ptr<Inanimate>>& ia , 
			std::vector<std::unique_ptr<Bomb>>& b ,int index, bool &nextLevel);

protected:

	sf::Vector2f m_pos, m_size;
	std::string m_img;
	sf::Texture m_texture;
	sf::RectangleShape m_rec;
	sf::Color m_color;
	bool m_visible;

	sf::SoundBuffer m_sb;
	sf::Sound m_s;

};

