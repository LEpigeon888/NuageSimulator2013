#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_NAME "Nuage Simulator 2013"
#define FRAMERATE 60

#include <SFML/Graphics.hpp>

#include "gameStateStack.hpp"

struct global
{
    static double timeFrame;
	static sf::RenderWindow window;
	static gameStateStackClass gameStateStack;
	static bool isFullScreen;
	static sf::Color skyColor;
	const static sf::Color skyBlueColor;
	const static sf::Color skyGreyColor;
    static bool isRain;
    static double percentChanceCreateCloud;
    static double timeCreateCloud;
};

#endif
