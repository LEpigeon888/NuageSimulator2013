#ifndef CLOUD_HPP
#define CLOUD_HPP

#define MAX_SIZE_CLOUD 150
#define MIN_SIZE_CLOUD 51
#define MAX_SIZE_MINI_CLOUD 50
#define MIN_SIZE_MINI_CLOUD 20
#define MAX_NMBR_MINI_CLOUD 5
#define MIN_NMBR_MINI_CLOUD 3
#define MAX_NMBR_SON_CLOUD 8
#define MIN_NMBR_SON_CLOUD 4
#define MAX_TRANSP_CLOUD 250
#define MIN_TRANSP_CLOUD 180

#include <deque>
#include <SFML/Graphics.hpp>

class cloudClass
{
public:
    cloudClass();
    void createRectangleCloud();
    void createMultipleRectangleCloud();
    void createMotherRectangleCloud();
    void draw();
    void update();
    bool stillAlive();
private:
    std::deque<sf::RectangleShape> listOfPartOfCloud;
    sf::Vector2f sizeOfCloud;
    sf::Vector2f posOfCloud;
    int speed;
};

#endif
