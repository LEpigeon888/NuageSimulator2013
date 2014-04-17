#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "gameStateStack.hpp"

class gameClass
{
public:
	gameClass();
	void run();
private:
	sf::Clock time;
};

#endif
