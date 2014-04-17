#include "cloud.hpp"
#include "global.hpp"

cloudClass::cloudClass()
{
    int numChoice = std::rand() % 100;
    speed = 1;
    if(numChoice < 20)
    {
        createMultipleRectangleCloud();
    }
    else if(numChoice < 30)
    {
        createMotherRectangleCloud();
    }
    else
    {
        createRectangleCloud();
    }
}

void cloudClass::draw()
{
    for(std::deque<sf::RectangleShape>::iterator ite = listOfPartOfCloud.begin(); ite != listOfPartOfCloud.end(); ++ite)
    {
        global::window.draw(*ite);
    }
}

void cloudClass::update()
{
    for(std::deque<sf::RectangleShape>::iterator ite = listOfPartOfCloud.begin(); ite != listOfPartOfCloud.end(); ++ite)
    {
        int tmpMove = static_cast<int>(-speed * global::timeFrame * FRAMERATE);
        if(tmpMove == 0)
        {
            tmpMove = -speed / speed;
        }
        ite->move(tmpMove, 0);
    }
}

bool cloudClass::stillAlive()
{
    if(global::isFullScreen == true)
    {
        return posOfCloud.x + sizeOfCloud.x >= 0;
    }
    else
    {
        return posOfCloud.x + sizeOfCloud.x >= 0;
    }
}

void cloudClass::createRectangleCloud()
{
    int tmpTrans = std::rand() % (MAX_TRANSP_CLOUD - MIN_TRANSP_CLOUD) + MIN_TRANSP_CLOUD;
    listOfPartOfCloud.resize(1);
    sizeOfCloud = sf::Vector2f(std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD, std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD);
    sf::RectangleShape partOfCloud(sizeOfCloud);
    partOfCloud.setFillColor(sf::Color(sf::Color::White.r, sf::Color::White.g, sf::Color::White.b, tmpTrans));
    partOfCloud.setOutlineColor(sf::Color(125, 125, 125, tmpTrans));
    partOfCloud.setOutlineThickness(3);
    if(global::isFullScreen == true)
    {
        posOfCloud = sf::Vector2f(global::window.getSize().x, std::rand() % static_cast<int>(global::window.getSize().y - sizeOfCloud.y));
    }
    else
    {
        posOfCloud = sf::Vector2f(WINDOW_WIDTH, std::rand() % static_cast<int>(WINDOW_HEIGHT - sizeOfCloud.y));
    }
    partOfCloud.setPosition(posOfCloud);
    listOfPartOfCloud.push_back(std::move(partOfCloud));
}

void cloudClass::createMultipleRectangleCloud()
{
    int tmpTrans = std::rand() % (MAX_TRANSP_CLOUD - MIN_TRANSP_CLOUD) + MIN_TRANSP_CLOUD;
    int numberPart = std::rand() % (MAX_NMBR_MINI_CLOUD - MIN_NMBR_MINI_CLOUD) + MIN_NMBR_MINI_CLOUD;
    listOfPartOfCloud.resize(numberPart);
    sizeOfCloud = sf::Vector2f(std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD, std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD);
    if(global::isFullScreen == true)
    {
        posOfCloud = sf::Vector2f(global::window.getSize().x, std::rand() % static_cast<int>(global::window.getSize().y - sizeOfCloud.y));
    }
    else
    {
        posOfCloud = sf::Vector2f(WINDOW_WIDTH, std::rand() % static_cast<int>(WINDOW_HEIGHT - sizeOfCloud.y));
    }

    for(int i = 0; i < numberPart; ++i)
    {
        sf::RectangleShape partOfCloud(sf::Vector2f(std::rand() % (MAX_SIZE_MINI_CLOUD - MIN_SIZE_MINI_CLOUD) + MIN_SIZE_MINI_CLOUD, std::rand() % (MAX_SIZE_MINI_CLOUD - MIN_SIZE_MINI_CLOUD) + MIN_SIZE_MINI_CLOUD));
        partOfCloud.setFillColor(sf::Color(sf::Color::White.r, sf::Color::White.g, sf::Color::White.b, tmpTrans));
        partOfCloud.setOutlineColor(sf::Color(125, 125, 125, tmpTrans));
        partOfCloud.setOutlineThickness(3);
        partOfCloud.setPosition(sf::Vector2f(std::rand() % static_cast<int>(sizeOfCloud.x - partOfCloud.getSize().x) + posOfCloud.x, std::rand() % static_cast<int>(sizeOfCloud.y - partOfCloud.getSize().y) + posOfCloud.y));
        listOfPartOfCloud.push_back(std::move(partOfCloud));
    }
}

void cloudClass::createMotherRectangleCloud()
{
    int tmpTrans = std::rand() % (MAX_TRANSP_CLOUD - MIN_TRANSP_CLOUD) + MIN_TRANSP_CLOUD;
    int numberPart = std::rand() % (MAX_NMBR_SON_CLOUD - MIN_NMBR_SON_CLOUD) + MIN_NMBR_SON_CLOUD;
    listOfPartOfCloud.resize(numberPart + 1);
    sf::RectangleShape motherOfCloud(sf::Vector2f(std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD, std::rand() % (MAX_SIZE_CLOUD - MIN_SIZE_CLOUD) + MIN_SIZE_CLOUD));
    motherOfCloud.setFillColor(sf::Color(sf::Color::White.r, sf::Color::White.g, sf::Color::White.b, tmpTrans));
    motherOfCloud.setOutlineColor(sf::Color(125, 125, 125, tmpTrans));
    motherOfCloud.setOutlineThickness(3);
    sizeOfCloud = sf::Vector2f(motherOfCloud.getSize().x + MAX_SIZE_MINI_CLOUD, motherOfCloud.getSize().y + MAX_SIZE_MINI_CLOUD);
    if(global::isFullScreen == true)
    {
        posOfCloud = sf::Vector2f(global::window.getSize().x, std::rand() % static_cast<int>(global::window.getSize().y - sizeOfCloud.y));
    }
    else
    {
        posOfCloud = sf::Vector2f(WINDOW_WIDTH, std::rand() % static_cast<int>(WINDOW_HEIGHT - sizeOfCloud.y));
    }
    motherOfCloud.setPosition(posOfCloud.x + (MAX_SIZE_MINI_CLOUD / 2), posOfCloud.y + (MAX_SIZE_MINI_CLOUD / 2));
    listOfPartOfCloud.push_back(std::move(motherOfCloud));

    for(int i = 0; i < numberPart; ++i)
    {
        int edge = std::rand() % 4;
        sf::Vector2f tmpPos;
        sf::RectangleShape partOfCloud(sf::Vector2f(std::rand() % (MAX_SIZE_MINI_CLOUD - MIN_SIZE_MINI_CLOUD) + MIN_SIZE_MINI_CLOUD, std::rand() % (MAX_SIZE_MINI_CLOUD - MIN_SIZE_MINI_CLOUD) + MIN_SIZE_MINI_CLOUD));
        partOfCloud.setFillColor(sf::Color(sf::Color::White.r, sf::Color::White.g, sf::Color::White.b, tmpTrans));
        partOfCloud.setOutlineColor(sf::Color(125, 125, 125, tmpTrans));
        partOfCloud.setOutlineThickness(3);
        tmpPos.x = 0;
        tmpPos.y = 0;
        if(edge == 0 || edge == 2)
        {
            tmpPos.x = std::rand() % static_cast<int>(sizeOfCloud.x - partOfCloud.getGlobalBounds().width) + posOfCloud.x;
            if(edge == 0)
            {
                tmpPos.y = posOfCloud.y + (MAX_SIZE_MINI_CLOUD / 2) - (partOfCloud.getSize().y / 2);
            }
            else
            {
                tmpPos.y = posOfCloud.y + sizeOfCloud.y - (MAX_SIZE_MINI_CLOUD / 2) - (partOfCloud.getSize().y / 2);
            }
        }
        else
        {
            tmpPos.y = std::rand() % static_cast<int>(sizeOfCloud.y - partOfCloud.getGlobalBounds().height) + posOfCloud.y;
            if(edge == 1)
            {
                tmpPos.x = posOfCloud.x + sizeOfCloud.x - (MAX_SIZE_MINI_CLOUD / 2) - (partOfCloud.getSize().x / 2);
            }
            else
            {
                tmpPos.x = posOfCloud.x + (MAX_SIZE_MINI_CLOUD / 2) - (partOfCloud.getSize().x / 2);
            }
        }
        partOfCloud.setPosition(tmpPos);
        listOfPartOfCloud.push_back(std::move(partOfCloud));
    }
}
