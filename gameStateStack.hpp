#ifndef GAMESTATESTACK_HPP
#define GAMESTATESTACK_HPP

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

#include "gameState.hpp"

class gameStateStackClass
{
public:
	void set(gameStateClass* state);
	void add(gameStateClass* state);
	void pop();
	void update();
	void draw();
	bool getChange();
	void setChange(bool val);
private:
	std::list<std::unique_ptr<gameStateClass>> stateList;
	bool change;
};

#endif
