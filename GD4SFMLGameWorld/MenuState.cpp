//Antony Saputra D00197615
//Conor Byrne D00185566

#include "MenuState.hpp"
#include "ResourceHolder.hpp"
#include "Utility.hpp"
#include "OptionID.hpp"


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(TextureID::TitleScreen);


	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(550, 360);
	playButton->setText("Play");
	playButton->setCallback([this]()
		{
			requestStackPop();
			requestStackPush(StateID::Game);
		});

	auto settingsButton = std::make_shared<GUI::Button>(context);
	settingsButton->setPosition(550, 410);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this]()
		{
			//requestStackPop();
			requestStackPush(StateID::Settings);
		});

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(550, 460);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
		{
			requestStackClear();

		});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);

	context.music->play(MusicID::MenuTheme);
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);

}

bool MenuState::update(sf::Time dt)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}

