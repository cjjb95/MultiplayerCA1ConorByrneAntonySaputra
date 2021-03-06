//Antony Saputra D00197615
//Conor Byrne D00185566

#include "State.hpp"
#include "StateStack.hpp"

State::State(StateStack& stack, Context context) : mStack(&stack), mContext(context)
{

}

State::~State()
{
}


void State::requestStackPush(StateID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStackClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player, Player& player2, SoundPlayer& sound, MusicPlayer& music) : 
	window(&window), textures(&textures), fonts(&fonts), player(&player), player2(&player2), sound(&sound), music(&music)
{
}
