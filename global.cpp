#include "global.hpp"

double global::timeFrame = 0;
sf::RenderWindow global::window;
gameStateStackClass global::gameStateStack;
bool global::isFullScreen = false;
const sf::Color global::skyBlueColor(73, 189, 218);
const sf::Color global::skyGreyColor(180, 180, 180);
bool global::isRain = false;
double global::percentChanceCreateCloud = 45;
double global::timeCreateCloud = 0.8;
