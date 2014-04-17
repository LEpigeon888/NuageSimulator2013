#include "playState.hpp"
#include "global.hpp"

playStateClass::playStateClass()
{
    transpPercent = 0;
    skyColor = global::skyBlueColor;
    timer.restart();
}

playStateClass::~playStateClass()
{

}

void playStateClass::update()
{
    sf::Event event;
    while(global::window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            global::window.close();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::F11:
                    if(global::isFullScreen == false)
                    {
                        global::window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Fullscreen);
                        global::isFullScreen = true;
                    }
                    else
                    {
                        global::window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
                        global::isFullScreen = false;
                    }
                    break;
                case sf::Keyboard::W:
                    global::isRain = !global::isRain;
                    break;

                case sf::Keyboard::Add:
                    global::percentChanceCreateCloud += 2;
                    if(global::percentChanceCreateCloud > 100)
                    {
                        global::percentChanceCreateCloud = 100;
                    }
                    break;

                case sf::Keyboard::Subtract:
                    global::percentChanceCreateCloud -= 2;
                    if(global::percentChanceCreateCloud < 0)
                    {
                        global::percentChanceCreateCloud = 0;
                    }
                    break;

                case sf::Keyboard::Multiply:
                    global::timeCreateCloud += 0.1;
                    break;

                case sf::Keyboard::Divide:
                    global::timeCreateCloud -= 0.1;
                    break;

                default:
                    break;
            }
        }
    }

    if(global::isRain == true)
    {
        if(transpPercent < 256)
        {
            ++transpPercent;
            skyColor = sf::Color((global::skyGreyColor.r * transpPercent / 255) + (global::skyBlueColor.r * (255 - transpPercent) / 255), (global::skyGreyColor.g * transpPercent / 255) + (global::skyBlueColor.g * (255 - transpPercent) / 255), (global::skyGreyColor.b * transpPercent / 255) + (global::skyBlueColor.b * (255 - transpPercent) / 255));
        }
    }
    else
    {
        if(transpPercent > 0)
        {
            --transpPercent;
            skyColor = sf::Color((global::skyGreyColor.r * transpPercent / 255) + (global::skyBlueColor.r * (255 - transpPercent) / 255), (global::skyGreyColor.g * transpPercent / 255) + (global::skyBlueColor.g * (255 - transpPercent) / 255), (global::skyGreyColor.b * transpPercent / 255) + (global::skyBlueColor.b * (255 - transpPercent) / 255));
        }
    }

    if(timer.getElapsedTime() > sf::seconds(global::timeCreateCloud))
    {
        if(std::rand() % 100 < global::percentChanceCreateCloud)
        {
            listOfCloud.push_back(std::unique_ptr<cloudClass>(new cloudClass()));
        }
        timer.restart();
    }
    for(std::list<std::unique_ptr<cloudClass>>::iterator ite = listOfCloud.begin(); ite != listOfCloud.end(); )
    {
        (*ite)->update();
        if((*ite)->stillAlive() == false)
        {
            listOfCloud.erase(ite++);
        }
        ++ite;
    }
}

void playStateClass::draw()
{
    global::window.clear(skyColor);
    for(std::list<std::unique_ptr<cloudClass>>::iterator ite = listOfCloud.begin(); ite != listOfCloud.end(); ++ite)
    {
        (*ite)->draw();
    }
}
