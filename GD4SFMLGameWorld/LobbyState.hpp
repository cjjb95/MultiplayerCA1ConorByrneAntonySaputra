#pragma once

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Container.hpp"
#include "Button.hpp"

class LobbyState : public State
{
public:
	LobbyState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);



private:
	sf::Sprite mBackgroundSprite;
	GUI::Container mGUIContainer;
};