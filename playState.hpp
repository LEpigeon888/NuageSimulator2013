#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <list>
#include <memory>

#include "gameState.hpp"
#include "cloud.hpp"

class playStateClass : public gameStateClass
{
public:
    playStateClass();
    ~playStateClass();
    void update();
    void draw();
private:
    std::list<std::unique_ptr<cloudClass>> listOfCloud;
    sf::Color skyColor;
    sf::Clock timer;
    int transpPercent;
};

#endif
