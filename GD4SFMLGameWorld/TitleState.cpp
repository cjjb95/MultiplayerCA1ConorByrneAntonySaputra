//Antony Saputra D00197615
//Conor Byrne D00185566

#include "TitleState.hpp"
#include "ResourceHolder.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "Utility.hpp"

TitleState::TitleState(StateStack& stack, Context context) : State(stack, context), mText(), mShowText(true), mTextEffectTime(sf::Time::Zero)
{
	mBackgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen)); //Sets the background image
	mText.setFont(context.fonts->get(FontID::Main));
	mText.setFillColor(sf::Color::Black);
	mText.setString("Press any key to start");
	centreOrigin(mText);
	mText.setPosition(context.window->getView().getSize() / 2.f);


}

void TitleState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
	{
		window.draw(mText);
	}
}

bool TitleState::update(sf::Time dt)
{
	mTextEffectTime += dt;
	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	//if keypressed trigger the next state
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(StateID::Menu);
	}
	return true;
}
