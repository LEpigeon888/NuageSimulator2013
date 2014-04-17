#include <iostream>

#include "game.hpp"
#include "global.hpp"
#include "playState.hpp"

gameClass::gameClass()
{
    std::srand(std::time(NULL));
	global::window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
	global::window.setFramerateLimit(FRAMERATE);
	global::window.setKeyRepeatEnabled(false);
	global::gameStateStack.set(new playStateClass());
	global::timeFrame = 1. / static_cast<double>(FRAMERATE);
}

void gameClass::run()
{
	while(global::window.isOpen())
	{
		time.restart();
		global::gameStateStack.update();
		while(global::gameStateStack.getChange())
		{
			global::gameStateStack.setChange(false);
			global::gameStateStack.update();
		}
        global::gameStateStack.draw();
		global::window.display();
		std::cout << 1. / global::timeFrame << std::endl;
		global::timeFrame = time.getElapsedTime().asSeconds();
	}
}
